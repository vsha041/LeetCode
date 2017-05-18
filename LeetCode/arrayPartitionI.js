/**
 * @param {number[]} nums
 * @return {number}
 */
var arrayPairSum = function (nums) {
    function comp(x, y) {
        if (x < y)
            return -1;
        if (x > y)
            return 1;
        return 0;
    }

    nums.sort(comp);
    var total = 0;
    for (var i = 0, j = 1; i < nums.length - 1; i += 2, j += 2) {
        var first = nums[i];
        var second = nums[j];
        var min = Math.min(first, second);
        total += min;
    }

    return total;
};