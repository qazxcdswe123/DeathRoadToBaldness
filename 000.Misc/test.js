async function f1() {
	console.log("f1");
}

async function f2() {
	console.log("f2");
}

function sleep() {
	console.log("done2");
	return new Promise((resolve) => {
		setTimeout(resolve, 1000);
		console.log("done1");
	});
}

async function main() {
	await sleep();
	f2();
	f1();
}

(function () {
	"use strict";
	main();
})();
