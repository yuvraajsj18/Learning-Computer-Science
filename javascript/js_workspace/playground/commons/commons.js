"use strict";

document.addEventListener("DOMContentLoaded", () => {
    let src = "./scripts/alertprompt.js";
    const script = document.createElement('script');
    script.setAttribute('src', src);
    document.querySelector("head").append(script);
});