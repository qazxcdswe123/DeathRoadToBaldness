// ==UserScript==
// @name         U校园unipus英语网课作业答案显示(不支持单元测试)
// @namespace    https://greasyfork.org
// @version      1.18
// @description  小窗口显示U校园板块测试答案
// @icon         https://ucontent.unipus.cn/favicon.ico
// @match        *://ucontent.unipus.cn/_pc_default/pc.html?*
// @match        *://u.unipus.cn/*
// @connect      unipus.cn
// @connect      fanyi.youdao.com
// @connect      translate.google.cn
// @connect      translate.google.com
// @connect      api.microsofttranslator.com
// @connect      api.fanyi.baidu.com
// @grant        GM_xmlhttpRequest
// @grant        GM.setClipboard
// @grant        GM.setValue
// @grant        GM.getValue
// @run-at       document-end
// @require      https://cdn.staticfile.org/jquery/3.6.0/jquery.min.js
// @require      https://lf9-cdn-tos.bytecdntp.com/cdn/expire-1-M/crypto-js/4.1.1/crypto-js.min.js
// @require      https://cdn.staticfile.org/blueimp-md5/1.0.1/js/md5.min.js
// @license      MIT
// ==/UserScript==

/**
 * Generate a random string
 * @param {number} length Length of this random string
 * @returns {string} The random string
 */
function randomString(length) {
	let abc = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	let ret = "";
	for (let i = 0; i < length; i++) {
		ret += abc.charAt(Math.floor(Math.random() * abc.length));
	}
	return ret;
}

/**
 * Generate a random num string
 * @param {number} length Length of this random num string
 * @returns {string} The random num string
 */
function randomNumString(length) {
	let nums = "0123456789";
	let ret = "";
	for (let i = 0; i < length; i++) {
		ret += nums.charAt(Math.floor(Math.random() * nums.length));
	}
	return ret;
}

/**
 * Async wait, default to 10 ms
 *
 * @param {number} ms How long to wait (in millisecond)
 * @returns {Promise<null>}
 */
async function sleep(ms = 10) {
	// 异步等待，只阻塞当前脚本调用处函数，不阻塞整个浏览器
	// 调用方法：await sleep() 或 await sleep (1000)
	return new Promise(function (resolve, reject) {
		setTimeout(() => {
			resolve();
		}, ms);
	});
}

async function getRequest(url, headers = {}, timeout = 5000) {
	return new Promise(function (resolve, reject) {
		// 由于 GM.xmlHttpRequest 默认不携带浏览器 cookie
		// 且 Grease Monkey 没有提供获取 HTTP-Only 的 cookie 的 API
		// 所以只能使用旧的 GM_xmlhttpRequest 来发起请求，否则会要求 SSO 登录
		GM_xmlhttpRequest({
			method: "GET",
			url: url,
			headers: headers,
			timeout: timeout,
			onload: (xhr) => {
				resolve(xhr);
			},
			onerror: (err) => {
				reject(err);
			},
			ontimeout: (err) => {
				reject(err);
			},
		});
	});
}

/**
 * Decrypt and parse "content" of XHR, thanks to SSmJaE for providing this function!
 * @param {String}} json Encrypted json or raw json string
 * @returns {Object} Object from raw json string
 */
function decryptContent(json) {
	if (json) {
		let r = json.content.slice(7),
			o = CryptoJS.enc.Utf8.parse("1a2b3c4d" + json.k),
			i = CryptoJS.enc.Hex.parse(r),
			a = CryptoJS.enc.Base64.stringify(i),
			contentJson = JSON.parse(
				CryptoJS.AES.decrypt(a, o, {
					mode: CryptoJS.mode.ECB,
					padding: CryptoJS.pad.ZeroPadding,
				}).toString(CryptoJS.enc.Utf8)
			);
		json = contentJson;
		console.log(json);
	}
	return json;
}

/**
 * Copy a string to clipboard
 * @param {string} str String to be copy
 */
function copyMe(str) {
	function _legacyCopy() {
		console.log("正在使用传统方法复制");
		let tmpInput = document.createElement("input");
		elem.insertAdjacentHTML("afterend", tmpInput);
		tmpInput.value = str;
		tmpInput.focus();
		tmpInput.select();
		if (document.execCommand("copy")) {
			document.execCommand("copy");
		}
		tmpInput.blur();
		console.log("复制成功");
		tmpInput.remove();
	}

	if (GM.setClipboard) {
		GM.setClipboard(str);
	} else if (navigator.clipboard && window.isSecureContext) {
		console.log("正在使用 navigator clipboard api 进行复制操作");
		navigator.clipboard.writeText(str).catch((err) => {
			console.log(
				"navigator clipboard api 复制时出错，将使用传统方法进行复制"
			);
			_legacyCopy();
		});
	} else {
		_legacyCopy();
	}
}

/**
 * Get token
 * @returns {Promise<string>} token or fallbackToken when error.
 */
async function getToken() {
	let fallbackToken =
		"eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJvcGVuX2lkIjoidHV4NkNCQVc4aGRrcnFZdzc5SEpEWDF2aTR5Z2ptcDUiLCJuYW1lIjoiIiwiZW1haWwiOiIiLCJhZG1pbmlzdHJhdG9yIjoiZmFsc2UiLCJleHAiOjE5MDI5NzAxNTcwMDAsImlzcyI6IlI0aG03RmxQOFdvS0xaMUNmTkllIiwiYXVkIjoiZWR4LnVuaXB1cy5jbiJ9.CwuQmnSmIuts3hHAMf9lT954rKHXUNkps-PfRJp0KnU";
	let oldToken = await GM.getValue("token");
	if (
		oldToken &&
		new Date(oldToken.expireWhen).getTime() > new Date().getTime()
	) {
		console.info("【U校园助手】正在使用旧的token");
		return oldToken.token;
	}
	console.info("【U校园助手】正在获取新的的token");
	let url = "https://u.unipus.cn/user/data/getToken";
	let xhr = await getRequest(url).catch((err) => {
		console.error(err);
		layui.use("layer", function () {
			layer.alert(`获取 Token 失败，请刷新重试\n错误信息：${err}`);
		});
		return fallbackToken;
	});
	if (xhr.status != 200) {
		layui.use("layer", function () {
			layer.alert(`获取 Token 失败，请刷新重试`);
		});
		return fallbackToken;
	}
	if (!xhr.responseText.startsWith("{")) {
		console.error("获取 Token 时的返回值：", xhr.responseText);
		if (xhr.responseText.includes("登录")) {
			layui.use("layer", function () {
				layer.alert("获取 Token 失败，请尝试重新登录");
			});
			return null;
		}
		alert(`获取 Token 失败，以下是 xhr 返回值：\n${xhr.responseText}`);
		return null;
	}
	let obj = JSON.parse(xhr.responseText);
	if (!obj || !obj.token) return fallbackToken;
	let token = obj.token;
	let expireWhen = new Date();
	expireWhen.setDate(expireWhen.getDate() + 1);
	let tokenObj = {
		token: token,
		expireWhen: expireWhen,
	};
	GM.setValue("token", tokenObj);
	return token;
}

/**
 * 显示答案浮窗
 */
function showPanel() {
	layer.open({
		type: 1,
		area: ["310px", "400px"],
		offset: "r",
		id: "msgt",
		closeBtn: 1,
		title: " ",
		shade: 0,
		maxmin: true,
		anim: 2,
		content: `<div class="layui-collapse"><div class="layui-colla-item"></div></div>
                <div id="content">
                    <table class="layui-table">
                        <colgroup>
                            <col width="100">
                            <col>
                            <col>
                        </colgroup>
                        <thead><tr></tr></thead>
                        <tbody></tbody>
                    </table>
                </div>`,
	});
}

/**
 * 解析并显示答案
 */
async function showanswer() {
	let url = location.href;
	let arr = url.split("/");
	let unit = arr[arr.length - 2];
	let course = /course-v1:.*?\//g.exec(url);
	course = course[0];
	let token = await getToken();
	let xhr = await getRequest(
		`https://ucontent.unipus.cn/course/api/content/${course}${unit}/default/`,
		{
			"X-ANNOTATOR-AUTH-TOKEN": token,
		},
		5000
	).catch((err) => {
		console.error(err);
		let el = `<tr class="layui-bg"><td>答案加载失败，请刷新重试。</td></tr>`;
		$("#content>table>tbody").append($(el));
	});
	if (xhr.status != 200) {
		let el = `<tr class="layui-bg"><td>答案加载失败，请刷新重试。</td></tr>`;
		$("#content>table>tbody").append($(el));
		return;
	}
	// obj.content 是加密后的题目信息
	let obj = JSON.parse(xhr.responseText) || {};
	if (!obj.content) {
		suggestFeedback(
			"U校园返回的内容中不包含'content'字段，检查api是否改变"
		);
		return;
	}
	// 对 api 返回的 content 进行解密
	var plainContent = decryptContent(obj) || {};

	console.log(plainContent);

	let questions = {};
	for (let key in plainContent) {
		// 将返回的多个或单个题目详情分别按序号装载到 questions 字典中
		let quesNo = 1;
		if (key.includes("content_")) {
			let re = /content_(\d+):/g.exec(key);
			quesNo = parseInt(re[1]);
		}
		questions[quesNo] = {
			key: key,
			content: plainContent[key],
		};
	}

	let quesNo = /p_(\d+)/g.exec(url);
	quesNo = quesNo[1];

	if (questions[quesNo].key.includes(":questions")) {
		// 选择题
		let answers = questions[quesNo].content.questions.map(
			(question) => question.answers
		);
		answers.forEach((answer, index) => {
			parseInt(index);
			let answerId = randomString(5);
			let btnId = randomString(5);
			let el = `<tr class="layui-bg"><td>
            <b>${index + 1}. </b>
            <code id="${answerId}">${answer.join("、")}</code>
            </td></tr>`;
			$("#content>table>tbody").append($(el));
			$(`#${btnId}`).on("click", function () {
				copyMe(answer);
			});
		});
		let find = window.setInterval(async function () {
			if (
				document.querySelector(
					".questions--questionDefault-2XLzl.undefined"
				)
			) {
				window.clearInterval(find);
				answers.forEach((answer, index) => {
					let questionElem = $(
						".questions--questionDefault-2XLzl.undefined"
					)[index];
					let options = questionElem.querySelectorAll(".clearfix");
					if (options.length == 0) {
						options = questionElem.querySelectorAll(
							".MultipleChoice--checkbox-2_VGC"
						);
					}
					for (let willSelect of answer) {
						let sel =
							willSelect.toUpperCase().charCodeAt(0) -
							"A".charCodeAt(0);
						options[sel].click();
					}
				});
			}
		}, 1000);
	} else if (questions[quesNo].key.includes(":scoopquestions")) {
		// 填空题
		$("#content>table>tbody").prepend(
			$(
				`<tr class="layui-bg"><td><b>无需在此面板中复制，点击题目中的空，直接粘贴即可。</b></td></tr>`
			)
		);
		let answers = questions[quesNo].content.questions.map(
			(question) => question.answers[0]
		);
		answers.forEach((answer, index) => {
			let answerId = randomString(5);
			let btnId = randomString(5);
			let el = `<tr class="layui-bg"><td>
                <b>${index + 1}. </b>
                <code id="${answerId}">${answer}</code>
                <button style="float:right;" id="${btnId}">复制</button>
            </td></tr>`;
			$("#content>table>tbody").append($(el));
			$(`#${btnId}`).on("click", function () {
				copyMe(answer);
			});
		});
		let interval = window.setInterval(function () {
			if (document.querySelector(".htmlViewBlank--holder_style-2dnxi")) {
				window.clearInterval(interval);
				answers.forEach((answer, index) => {
					$($(".htmlViewBlank--holder_style-2dnxi")[index]).on(
						"click",
						function () {
							copyMe(answer);
						}
					);
				});
			}
		}, 1000);

		// } else if (questions[quesNo].key.includes(':shortanswer') && questions[quesNo].content.category === "shortanswer:shortAnswer") {
		//     // 翻译题
		//     let question = questions[quesNo].content.content[0].html.html;
		//     question = question.replace(/<.*?>|\(.*?\)|（.*?）/g, "");
		//     let direction = 'zh2en';
		//     if (/^[a-zA-Z\.,\s]+$/g.test(question.substring(0, 5))) direction = 'en2zh';
		//     let translator = await Translator.new(question, direction);
		//     try {
		//         // 谷歌翻译
		//         let result = translator.google;
		//         let answerId = randomString(5);
		//         let btnId = randomString(5);
		//         $("#content>table>tbody").append($(`
		//                 <tr class="layui-bg"><td>
		//                     <b>谷歌翻译：</b>
		//                     <code id="${answerId}">${result}</code>
		//                     <button style="float:right;" id="${btnId}">复制</button>
		//                 </td></tr>`));
		//         $(`#${btnId}`).on("click", function () {
		//             copyMe(result);
		//         });
		//     } catch (e) {
		//         console.error(e);
		//     }
		//     try {
		//         // 百度翻译
		//         let result = translator.baidu;
		//         let answerId = randomString(5);
		//         let btnId = randomString(5);
		//         $("#content>table>tbody").append($(`
		//                 <tr class="layui-bg"><td>
		//                     <b>百度翻译：</b>
		//                     <code id="${answerId}">${result}</code>
		//                     <button style="float:right;" id="${btnId}">复制</button>
		//                 </td></tr>`));
		//         $(`#${btnId}`).on("click", function () {
		//             copyMe(result);
		//         });
		//     } catch (e) {
		//         console.error(e);
		//     }
		//     try {
		//         // 必应翻译
		//         let result = translator.bing;
		//         let answerId = randomString(5);
		//         let btnId = randomString(5);
		//         $("#content>table>tbody").append($(`
		//                 <tr class="layui-bg"><td>
		//                     <b>必应翻译：</b>
		//                     <code id="${answerId}">${result}</code>
		//                     <button style="float:right;" id="${btnId}">复制</button>
		//                 </td></tr>`));
		//         $(`#${btnId}`).on("click", function () {
		//             copyMe(result);
		//         });
		//     } catch (e) {
		//         console.error(e);
		//     }
		//     try {
		//         let answer = questions[quesNo].content.analysis.html;
		//         answer = answer.replace(/<.*?>/g, "").replace(/\d\.\s?(&nbsp;)?/g, "");
		//         let el = `
		//         <tr class="layui-bg"><td>
		//             <b>标准答案（仅供参考）：</b>
		//             ${answer}
		//         </td></tr>`;
		//         $("#content>table>tbody").append($(el));
		//     } catch (e) {
		//         console.error(e);
		//     }
	} else if (
		questions[quesNo].key.includes(":shortanswer") ||
		questions[quesNo].key.includes(":scoopshortanswer")
	) {
		// 简答题
		if (
			questions[quesNo].key.includes(":shortanswer") &&
			questions[quesNo].content.category === "shortanswerScoop"
		) {
			if (questions[quesNo].content.analysis.html.length > 0) {
				let answer = questions[quesNo].content.analysis.html;
				answer = answer
					.replace(/<.*?>/g, "")
					.replace(/\d\.\s?(&nbsp;)?/g, "");
				let answerId = randomString(5);
				let btnId = randomString(5);
				let el = `
                <tr class="layui-bg"><td>
                    <b>标准答案（仅供参考）：</b>
                    <code id="${answerId}">${answer}</code>
                    <button style="float:right;" id="${btnId}">复制</button>
                </td></tr>`;
				$("#content>table>tbody").append($(el));
				$(`#${btnId}`).on("click", function () {
					copyMe(answer);
				});
			} else {
				let answers = questions[quesNo].content.questions.map(
					(question) =>
						question.analysis.html
							.replace(/<.*?>/g, "")
							.replace(/\d\.\s?(&nbsp;)?/g, "")
				);
				answers.forEach((answer, index) => {
					let answerId = randomString(5);
					let btnId = randomString(5);
					let el = `
                    <tr class="layui-bg"><td>
                        <b>${index + 1}.（仅供参考）</b>
                        <code id="${answerId}">${answer}</code>
                        <button style="float:right;" id="${btnId}">复制</button>
                    </td></tr>`;
					$("#content>table>tbody").append($(el));
					$(`#${btnId}`).on("click", function () {
						copyMe(answer);
					});
				});
			}
		} else {
			let answers = questions[quesNo].content.questions.map((question) =>
				question.analysis.html
					.replace(/<.*?>/g, "")
					.replace(/\d\.\s?(&nbsp;)?/g, "")
			);
			answers.forEach((answer, index) => {
				let answerId = randomString(5);
				let btnId = randomString(5);
				let el = `
                <tr class="layui-bg"><td>
                    <b>${index + 1}.（仅供参考）</b>
                    <code id="${answerId}">${answer}</code>
                    <button style="float:right;" id="${btnId}">复制</button>
                </td></tr>`;
				$("#content>table>tbody").append($(el));
				$(`#${btnId}`).on("click", function () {
					copyMe(answer);
				});
			});
		}
	} else if (questions[quesNo].key.includes(":sequence")) {
		// 排序题
		let answers = questions[quesNo].content.questions.map(
			(question) => question.answer
		);
		answers.forEach((answer, index) => {
			let el = `<tr class="layui-bg"><td>
                <b>${index + 1}. </b>
                <code>${answer}</code>
                
            </td></tr>`;
			$("#content>table>tbody").append($(el));
		});
	} else if (questions[quesNo].key.includes(":bankedcloze")) {
		// 十五选十
		let answers = questions[quesNo].content.questions.map(
			(question) => question.answer
		);
		$("#content>table>tbody").prepend(
			$(
				`<tr class="layui-bg"><td><b>无需在此面板中复制，点击题目中的空，直接粘贴即可。</b></td></tr>`
			)
		);
		answers.forEach((answer, index) => {
			let answerId = randomString(5);
			let btnId = randomString(5);
			let el = `
            <tr class="layui-bg"><td>
                <b>${index + 1}. </b>
                <code id=${answerId}>${answer}</code>
                <button style="float:right;" id="${btnId}">复制</button>
            </td></tr>`;
			$("#content>table>tbody").append($(el));
			$(`#${btnId}`).on("click", function () {
				copyMe(answer);
			});
		});
		let find = window.setInterval(function () {
			if ($(".cloze-text-pc--bc-input-k5WJk").length > 0) {
				window.clearInterval(find);
				answers.forEach((item, index) => {
					$($(".cloze-text-pc--bc-input-k5WJk")[index]).on(
						"click",
						function () {
							copyMe(item);
						}
					);
				});
			}
		}, 1000);
	} else if (questions[quesNo].key.includes(":scoopselection")) {
		// 下拉选择题
		let answers = questions[quesNo].content.questions.map((question) => {
			let result = [];
			for (let willSelect of question.answers) {
				// willSelect 为选项，即 A、B、C、D，可在 options 中找到对应的文字内容
				for (let option of question.options) {
					if (option.caption === willSelect) {
						result.push(
							option.content.html
								.replace(/<.*?>/g, "")
								.replace(/\d\.\s?(&nbsp;)?/g, "")
						);
					}
				}
			}
			return result;
		});
		answers.forEach((answer, index) => {
			let el = `
            <tr class="layui-bg"><td>
                <b>${index + 1}. </b>
                <code>${answer.join("、")}</code>
            </td></tr>`;
			$("#content>table>tbody").append($(el));
		});
	}
}

function main() {
	if (window.location.href.includes("u.unipus.cn")) {
		window.setInterval(function () {
			if (
				document.getElementsByClassName("layui-layer-shade").length >
					0 &&
				document.querySelectorAll(".layui-layer-dialog").length > 0
			) {
				// 去除环境检测弹窗
				document.querySelector(".layui-layer-shade").remove();
				document.querySelector(".layui-layer-dialog").remove();
			}
		}, 100);
	}
	if (window.location.href.includes("ucontent.unipus.cn")) {
		window.setInterval(function () {
			if (
				document.querySelector(".taskTipStyle--tipBody-2h6eh") &&
				document
					.querySelector(".taskTipStyle--tipBody-2h6eh")
					.innerText.includes("本单元学习时间")
			) {
				document.querySelector('button[type="button"]').click();
			}
		}, 100);
		$("head").append(
			'<link href="https://cdn.staticfile.org/layui/2.6.8/css/layui.css" rel="stylesheet" type="text/css" />'
		);
		let onload = function (data, status, jqxhr) {
			layui.use("element", function () {
				let element = layui.element;
			});
			layer.closeAll();
			showPanel();
			showanswer();
		};
		$.getScript(
			"https://cdn.staticfile.org/layui/2.6.8/layui.min.js",
			onload
		).fail(function () {
			if (arguments[0].readyState == 0) {
				//加载失败则更换一个 CDN 源
				$.getScript(
					"https://lf6-cdn-tos.bytecdntp.com/cdn/expire-1-M/layui/2.6.8/layui.min.js",
					onload
				).fail(function () {
					suggestFeedback(
						"Layui 外部库加载失败，请检查网络连接后刷新重试，若重试仍不成功"
					);
				});
			} else {
				//script loaded but failed to parse
				suggestFeedback(
					"解析 Layui 外部库时出现错误：" + arguments[2].toString()
				);
			}
		});

		let autoClickPlay = window.setInterval(async function () {
			if (
				document.querySelector(".audio--aplayer-mute-2VMS7") &&
				document.querySelector(
					".audio--aplayer-rate-ms-ZWyM6.audio--aplayer-rate-m-aH2Eu"
				) &&
				document.querySelector(".audio--aplayer-play-3oL9n")
			) {
				window.clearInterval(autoClickPlay);
				await sleep(500);
				// 点击倍速
				document
					.querySelector(
						".audio--aplayer-rate-ms-ZWyM6.audio--aplayer-rate-m-aH2Eu"
					)
					.querySelectorAll("span")[2]
					.click();
				await sleep(300);
				// 点击静音
				document.querySelector(".audio--aplayer-mute-2VMS7").click();
				await sleep(300);
				// 点击播放
				document.querySelector(".audio--aplayer-play-3oL9n").click();
			}
		}, 500);

		window.onhashchange = () => {
			$("#content>table>tbody").empty();
			main();
		};
	}
}

(function () {
	"use strict";
	main();
})();
