/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
    // nums is an array - for e.g. [1, 22, 34, 1]
    // target is the sum we want to acheive - for e.g. []

    var dict = Object.create(null);
    var answer = [];

    for (var i = 0; i < nums.length; i++) {
        var key = nums[i].toString();

        if (dict[key] == null || dict[key] == undefined) {
            var arr = [];
            arr.push(i);
            dict[key] = arr;
        } else {
            dict[key].push(i);
        }
    }

    for (var j = 0; j < nums.length; j++) {
        var first = nums[j];
        var expected = target - first;

        if (dict[expected.toString()] != null && dict[expected.toString()] != undefined) {
            var values = dict[expected.toString()];
            if (first === expected) {
                if (values.length === 2) {
                    answer.push(values[0]);
                    answer.push(values[1]);
                    break;
                }
            } else {
                var second2 = values[0];
                answer.push(j);
                answer.push(second2);
                break;
            }
        }
    }
    return answer;
};