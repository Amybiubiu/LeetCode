/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    let res = "";
    let i = 0;
    let n = s.length;
    while(i < n){
        let word = "";
        while(i < n && s[i] === ' '){
            i++;
        }
        while(i < n && s[i] !== ' '){
            word += s[i++];
        }
        if(word !== "") word += ' ';
        res = word + res;
    }
    return res.slice(0, res.length - 1);
};

class Solution {
public:
    string reverseWords(string s) {
        int len = s.length(), i = 0;
        string ans = "", tmp;
        while(i < len){
            tmp = "";
            while(i < len && s[i] == ' ') i++;
            while(i < len && s[i] != ' ') tmp += s[i++];
            if(tmp != ""){
                ans = tmp + " " + ans;
            }
        }
        return ans.substr(0, ans.length()-1);
    }
};