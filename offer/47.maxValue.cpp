class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size();
        if(!m) return 0;
        int n = grid[0].size();
        if(!n) return 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                dp[i+1][j+1] = grid[i][j] + max(dp[i][j+1], dp[i+1][j]);
            }
        }
        return dp[m][n];
    }
};