/**
 * @param {string} s
 * @return {character}
 */
 var firstUniqChar = function(s) {
    var dic = new Map();
    for(let i = 0; i < s.length; i++){
        let num = dic.get(s[i]);
        if(!num){
            dic.set(s[i], 1);
        }else{
            dic.set(s[i], num+1);
        }
    }
    for(let i = 0; i < s.length; i++){
        if(dic.get(s[i]) == 1)
            return s[i];
    }
    return ' ';
};