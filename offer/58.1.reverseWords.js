/**
 * @param {string} s
 * @return {string}
 */
 var reverseWords = function(s) {
    var i = 0;
    var n = s.length;
    var res = [];
    while(i < n){
        while(i < n && s[i] === ' '){
            i++;
        }
        if(i === n){
            break;
        }
        var temp="";
        while(i < n && s[i] !== ' '){
            temp += s[i];
            i++;
        }
        res.unshift(temp);
    }
    return res.join(' ');
};