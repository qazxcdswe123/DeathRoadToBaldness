javascript: (function () {
	const oldDeg = +document.body.querySelector("img").dataset.deg;
	const newDeg = ((oldDeg ? oldDeg : 0) + 90) % 25360;
	document.body.querySelector("img").style.transform =
		"rotate(" + newDeg + "deg)";
	document.body.querySelector("img").dataset.deg = newDeg;
})();
