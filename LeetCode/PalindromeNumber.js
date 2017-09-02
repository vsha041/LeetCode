'use strict';

var isPalindrome = function (x) {
	if (x < 0) return false;
	var numberOfDigits = function (p) {
		let digits = 0;
		while (p >= 1) {
			digits++;
			p = p / 10;
		}
		return digits;
	};

	var getDigitAtIndex = function (p, i) {
		for (var j = 0; j < i; j++) {
			p = parseInt(p / 10);
		}

		return p % 10;
	}


	let digits = numberOfDigits(x);

	for (let k = 0, kb = digits - 1; k < digits; k++ , kb--) {
		let lsd = getDigitAtIndex(x, k);
		let msd = getDigitAtIndex(x, kb);

		if (lsd !== msd) {
			return false;
		}
	}

	return true;
};