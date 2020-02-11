/**
 * @param {string} word
 * @return {boolean}
 */
var detectCapitalUse = function(word) {
    var newstr = word.slice(1);
    var fir = word[0];
    return (fir == fir.toUpperCase())?helper(newstr):helper(word);
};
var helper = function(str){
    var up = (str == str.toUpperCase());
    var lo = (str == str.toLowerCase());
    return up||lo;
}