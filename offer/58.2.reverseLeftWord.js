/**
 * @param {string} s
 * @param {number} n
 * @return {string}
 */
 var reverseLeftWords = function(s, n) {
    var size = s.length;
    n = n % size;
    return s.slice(n) + s.slice(0, n);
};