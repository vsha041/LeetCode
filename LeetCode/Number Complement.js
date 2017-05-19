/**
 * @param {number} num
 * @return {number}
 */
var findComplement = function (num) {
    var bits = Math.floor(Math.log2(num)) + 1;
    var maximum = Math.pow(2, bits) - 1;
    return maximum - num;
};