class Solution {
public:
    /**
     * 最大正方形
     * @param matrix char字符型vector<vector<>> 
     * @return int整型
     */
    int solve(vector<vector<char> >& matrix) {
        // write code here
        int m = matrix.size();
        int n = matrix[0].size();
        if(!m || !n) return 0;
        int res = 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1'){
//                     dp[i+1][j+1] = 1;
//                     if(dp[i][j+1] && dp[i+1][j]){
//                         dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+1);
//                     }
                    dp[i+1][j+1] = min(min(dp[i][j+1], dp[i+1][j]), dp[i][j]) + 1;
                    res = max(res, dp[i+1][j+1]);
                }
            }
        }
        return res*res;
    }
};