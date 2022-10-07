// ==UserScript==
// @name        Douban Search Book
// @namespace   ynchen.me
// @match       https://book.douban.com/*
// @version     1.0
// @author      yn
// @description 02/10/2022, 19:13:13
// ==/UserScript=='use strict'

(function () {
	let host = location.hostname;
	let path = location.pathname;
	if (host === "book.douban.com" && path !== "/") {
		const ISBNOfBook = document
			.querySelector("#info")
			.innerText.match(/ISBN: (.*)/)[1];
		const Title = document.querySelector("#wrapper h1 span");

		const styleForSearch =
			"<style>.sytleForSearch{vertical-align: middle;}.styleForSearch:hover{background: #fff!important;}</style>";

		const jumpToLibgen = document.createElement("libgen");
		jumpToLibgen.innerHTML =
			styleForSearch +
			`<a href="https://libgen.is/search.php?req=${ISBNOfBook}&column=identifier" class="styleForSearch" target="_blank"> <?xml version="1.0" encoding="UTF-8" standalone="no"?>
        <svg version="1.1" width="32px" height="23px" id="Layer_1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
	 viewBox="0 0 578 814" style="enable-background:new 0 0 578 814;" xml:space="preserve">
<g>
	<path class="st0" d="M442.177002,617.056396c44.699585,11.371399,50.26297,110.305176-10.930725,165.361084
		c-29.200989,26.272156-77.925385,28.040222-141.130157,30.717407c-182.909271,7.747437-170.068069-54.021606-170.068069-89.035645
		s22.008804-35.014038,22.008804-35.014038C376.150574,690.085632,442.177002,617.056396,442.177002,617.056396z"/>
	<path class="st0" d="M158.856979,340.889404c68.390289-9.929047,146.151901-14.949524,232.299576-14.949524
		c26.500244,0,49.25592,0.663147,69.05835,2.070343c23.100006-22.384644,26.966492-62.497742,26.966492-86.158035
		c0-28.0112-23.590454-82.979187-153.047638-82.979187c-217.276184,0-281.504669,34.013611-281.504669,34.013611
		C108.167931,226.776581,147.028641,312.219421,158.856979,340.889404z"/>
	<path class="st0" d="M0,433.983124c0,0,104.041641-58.023224,391.156555-58.023224
		c128.022888,0,162.986206,15.764099,179.715332,58.981171c17.723145,45.784729,2.357544,136.096893-45.661682,159.10611
		c0,0,1.000427-17.006775-104.041626-17.006775s-266.106506,58.023193-266.106506,58.023193S94.037643,471.998322,0,433.983124z"/>
	<path class="st0" d="M205.644806,113.380119c38.801361-3.010727,81.720825-4.527145,128.488953-4.527145
		c22.533722,0,43.341919,1.542183,62.394653,4.592781c-4.388367-21.212166-14.06369-51.887589-35.38385-81.623611
		C307.830627,11.721445,197.632996-14.563307,145.05806,9.813333C145.05806,9.813333,187.785675,46.108135,205.644806,113.380119z"
		/>
</g>
</svg>
 </a>`;
		Title.appendChild(jumpToLibgen);

		const jumpToZlib = document.createElement("zlib");
		jumpToZlib.innerHTML = `<a href="https://b-ok.global/s/${ISBNOfBook}" class="styleForSearch" target="_blank"> <?xml version="1.0" encoding="UTF-8" standalone="no"?> 
<svg width="32px" height="23px" viewBox="0 0 48 48" fill="none" xmlns="http://www.w3.org/2000/svg">
<rect width="48" height="48" rx="4" fill="white"/>
<path d="M16.5635 5.5177L23.1434 25.4927L23.1463 25.4916L23.2292 25.7334C23.5446 25.6031 23.8863 25.5243 24.2479 25.519C24.6351 25.5126 25.009 25.5891 25.3542 25.7299L25.4336 25.5097L25.4465 25.5143L31.7921 5.5177H31.4025L25.186 25.0862L29.0603 5.5177H28.6824L24.8886 24.6259L26.7052 5.5177H26.332L24.478 25.1668C24.4511 25.165 24.4255 25.161 24.3986 25.1598L24.4383 25.1592L24.5551 5.5177H24.1819L24.0656 25.165H24.075C24.0586 25.1662 24.0429 25.1691 24.0265 25.1703L22.401 5.5177H22.0266L23.613 24.8087L19.4519 5.5177H19.0716L23.1246 24.3082L16.9554 5.5177H16.5635V5.5177Z" fill="#C7C6C7"/>
<path d="M26.2748 44.2895V32.4615H22.0815V44.2895L24.1779 42.1318L26.2748 44.2895Z" fill="#49AFD0"/>
<path d="M37.7385 4.2002L32.7492 5.51793L25.2961 25.7108H23.2424L15.8202 5.41044L10.7993 4.2002L20.4206 30.3462L28.2148 30.3538L37.7385 4.2002Z" fill="#626062"/>
</svg></a>`;
		Title.appendChild(jumpToZlib);
	}
})();
