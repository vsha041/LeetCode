var reverse = function (x) {
    var isGreaterThanInt32 = function (str) {
        var max = 2147483647;
        var result = 0;
        var length = str.length;
        for (var i = 0, j = length - 1; i < length; i++ , j--) {
            var num = parseInt(str[j], 10);
            result += Math.pow(10, i) * num;
            if (result > max)
                return true;
        }
        return false;
    };

    var reverseString = function (str) {
        var split = str.split('').reverse().join('');
        return split;
    }

    var isNegative = x < 0 ? true : false;

    if (isNegative) {
        x = x * -1;
    }

    var str = x.toString();

    str = reverseString(str);

    var overflow = isGreaterThanInt32(str);
    if (overflow === true) {
        return 0;
    }

    if (isNegative)
        return -parseInt(str);
    else
        return parseInt(str);
};