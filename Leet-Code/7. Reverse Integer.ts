/*
 * Link: https://leetcode.com/problems/reverse-integer/
 *
 * I'll be honest the whole using strings is definately a hack, but it works...
*/

function reverse(x: number): number {
    let strNum = x.toString()
    let reversedNum = 0
    if (x < 0) {
        strNum = strNum.replace('-', '')
        strNum = strNum.split("").reverse().join("")
        strNum = '-' + strNum
        reversedNum = parseInt(strNum, 10)
    } else {
        strNum = strNum.split("").reverse().join("")
        reversedNum = parseInt(strNum, 10)
    }

    if ((reversedNum > Math.pow(2, 31) - 1) || reversedNum < -1 * Math.pow(2, 31)) {
        return 0
    }
    return reversedNum
};
