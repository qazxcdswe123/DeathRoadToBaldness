// ==UserScript==
// @name         Unipus Auto Filling
// @namespace    https://greasyfork.org
// @version      1.0
// @description  U 校园自动填充
// @icon         https://ucontent.unipus.cn/favicon.ico
// @match        *://ucontent.unipus.cn/_pc_default/pc.html?*
// @match        *://u.unipus.cn/*
// @connect      unipus.cn
// @grant        GM_xmlhttpRequest
// @grant        GM.setValue
// @grant        GM.getValue
// @run-at       document-end
// @require      https://cdn.staticfile.org/jquery/3.6.1/jquery.min.js
// @require      https://lf9-cdn-tos.bytecdntp.com/cdn/expire-1-M/crypto-js/4.1.1/crypto-js.min.js
// @license      MIT
// ==/UserScript==

// Login URL: https://u.unipus.cn/user/student/mycourse/courseCatalog?courseId=555&school_id=&eccId=81234&classId=559991&coursetype=0

async function sleep(ms = 10) {
	return new Promise(function (resolve, reject) {
		setTimeout(() => {
			resolve();
		}, ms);
	});
}

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

async function getToken() {
	let fallbackToken =
		"eyJhbGciOiJIUzI1NiJ9.eyJhdWQiOiJlZHgudW5pcHVzLmNuIiwib3Blbl9pZCI6ImQzNDA5YzZlY2FlMDRlNTI5NzZlM2JjZWJlZGMxMWU2Iiwib3BlbklkIjoiZDM0MDljNmVjYWUwNGU1Mjk3NmUzYmNlYmVkYzExZTYiLCJpc3MiOiJjNGY3NzIwNjNkY2ZhOThlOWM1MCIsImV4cCI6MTY2MzA2NTIwODI0N30.hRjN2u5ZODoZRPx5brgw9VgdC2fn2OwQo8drygRAsk0";
	let oldToken = await GM.getValue("token");
	if (
		oldToken &&
		new Date(oldToken.expireWhen).getTime > new Date().getTime()
	) {
		console.info("Using old token");
		return oldToken.token;
	}

	let url = "https://u.unipus.cn/user/data/getToken";
	let xhr = await getRequest(url).catch((err) => {
		console.error(err);
		return fallbackToken;
	});

	if (xhr.status !== 200) {
		console.error(xhr);
		return fallbackToken;
	}

	if (!xhr.responseText.startsWith("{")) {
		console.error(xhr.responseText);
		return fallbackToken;
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

async function getAnswer() {
	let url = window.location.href;
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
	});

	if (xhr.status != 200) {
		console.error("HTTP Code != 200");
		console.error(xhr);
		return;
	}

	let obj = JSON.parse(xhr.responseText) || {}; //
	if (!obj || !obj.content) {
		console.error("API may changed");
		console.error(obj);
		return;
	}

	let plainContent = (await decryptContent(obj)) || {};
	console.log(plainContent);

	let questions = {};
	for (let question in plainContent) {
		let quesNo = 1;
		if (question.includes("content_")) {
			let re = /content_(\d+)/g.exec(question);
			quesNo = parseInt(re[1]);
		}
		questions[quesNo] = {
			key: question,
			content: plainContent[question],
		};
	}

	return questions;
}

async function submitAnswer(questions) {
	let url = window.location.href;
	let quesNo = /p_(\d+)/g.exec(url);
	quesNo = quesNo[1];

	if (questions[quesNo].key.includes(":questions")) {
		// choice question
		let answers = questions[quesNo].content.questions.map(
			(question) => question.answers
		);
		answers.forEach((answer, index) => {
			// eg: `document.querySelector('[name="single-5"][value="B"]')`
			let selector = `[name='single-${index + 1}'][value='${answer}']`;
			let ele = document.querySelector(selector);
			console.log(ele);
			if (ele) ele.click();
		});
		console.log(answers);
	} else if (questions[quesNo].key.includes(":scoopquestions")) {
		// cloze question
		let answers = questions[quesNo].content.questions.map(
			(question) => question.answers[0]
		);
		answers.forEach(async (answer, index) => {
			let selector = ".htmlViewBlank--holder_style-2dnxi";
			let ele = document.querySelectorAll(selector)[index];
			// find the innermost element
			while (ele.children.length > 0) {
				ele = ele.children[0];
			}
			ele.setAttribute("value", answer);
			ele.value = answer;
		});
	} else if (
		questions[quesNo].key.includes(":shortanswer") ||
		questions[quesNo].key.includes(":scoopshortanswer")
	) {
		// short answer question
		let answers = undefined;
		if (questions[quesNo].content.analysis.length > 0) {
			answers = questions[quesNo].content.analysis.html;
			answers = answers
				.replace(/<.*?>/g, "")
				.replace(/\d\.\s?(&nbsp;)?/g, "");
		} else {
			answers = questions[quesNo].content.questions.map((question) =>
				question.analysis.html
					.replace(/<.*?>/g, "")
					.replace(/\d\.\s?(&nbsp;)?/g, "")
			);
		}
		answers.forEach((answer, index) => {
			let selector = ".writing--textarea-36VPs";
			let ele = document.querySelectorAll(selector)[index];
			ele.value = answer;
		});

		console.log(answers);
	} else if (questions[quesNo].key.includes(":sequence")) {
		// sorting question
		let answers = questions[quesNo].content.questions.map(
			(question) => question.answer
		);
		console.info(answers);
	} else if (questions[quesNo].key.includes(":bankedcloze")) {
		// select 10 in 15
		let answers = questions[quesNo].content.questions.map(
			(question) => question.answer
		);
		console.info(answers);
	}
}

function removeEnvironmentPopUp() {
	if (window.location.href.includes("u.unipus.cn")) {
		window.setInterval(function () {
			if (document.querySelector(".pop-up")) {
				document.querySelector(".pop-up").remove();
			}
		}, 100);
	}
}

function removeInTestPopUp() {
	if (window.location.href.includes("ucontent.unipus.cn")) {
		window.setInterval(function () {
			if (document.querySelector(".iKnow")) {
				document.querySelector(".iKnow").click();
			}
			if (
				document.querySelector(".taskTipStyle--tipBody-2h6eh") &&
				document
					.querySelector(".taskTipStyle--tipBody-2h6eh")
					.innerText.includes("本单元学习时间")
			) {
				document.querySelector('button[type="button"]').click();
			}
		}, 100);
	}
}

async function main() {
	removeEnvironmentPopUp();
	removeInTestPopUp();
	await sleep(1000);
	const ans = await getAnswer();
	await submitAnswer(ans);

	window.onhashchange = () => {
		main();
	};
}

(function () {
	"use strict";
	main();
})();
