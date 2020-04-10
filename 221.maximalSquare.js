/**
 * @param {character[][]} matrix
 * @return {number}
 */
var maximalSquare = function (matrix) {
    var m = matrix.length;
    var n = m > 0 ? matrix[0].length : 0;
    // let arr = Array(3).fill({})
    // var dp = Array(m + 1).fill(Array(n + 1).fill(0));
    var dp = [];
    for(let i = 0;i<= m;i++){
        dp[i] = [];
        for(let j = 0;j <= n;j++){
            dp[i][j] = 0;
        }
    }
    var res = 0;
    for (var i = 1; i <= m; i++) {
        for (var j = 1; j <= n; j++) {
            if (matrix[i - 1][j - 1] == "1") {
                dp[i][j] = Math.min(Math.min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                res = Math.max(res, dp[i][j]);
            }
        }
    }
    return res * res;
};
//java
public class Solution {
    public int maximalSquare(char[][] matrix) {
        int rows = matrix.length, cols = rows > 0 ? matrix[0].length : 0;
        int[][] dp = new int[rows + 1][cols + 1];
        int maxsqlen = 0;
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                if (matrix[i-1][j-1] == '1'){
                    dp[i][j] = Math.min(Math.min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                    maxsqlen = Math.max(maxsqlen, dp[i][j]);
                }
            }
        }
        return maxsqlen * maxsqlen;
    }
}


