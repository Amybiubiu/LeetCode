/**
 * @param {string} s
 * @return {string}
 */
var replaceSpace = function(s) {
    let a = s.split(' ');
    let res = '';
    for(let i = 0; i < a.length - 1; i++){
        res = res + a[i] + "%20";
    }
    res += a[a.length-1];
    return res;
};