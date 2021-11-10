/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    let n = s.length;
    let j = n-1;
    let res = 0;
    // while(j >= 0){
        while(j >= 0 && s[j] === ' '){
            j--;
        }
        while(j >= 0 && s[j] !== ' '){
            res += 1;
            j--;
        }
        // break;
    //}
    return res;
};