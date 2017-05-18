/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var hammingDistance = function (x, y) {
    let result = x ^ y;
    let ones = 0;
    for (let i = 0; i < 31; i++) {
        let power = 1 << i;
        if ((result & power) > 0) {
            ++ones;
        }
    }

    return ones;
};