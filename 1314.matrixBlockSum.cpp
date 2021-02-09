class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> prefix(m+1, vector<int>(n+1, 0));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + mat[i-1][j-1];
            }
        }
        
        vector<vector<int>> res(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int row1 = max(0, i - K);
                int col1 = max(0, j - K);
                int row2 = min(m-1, i + K);
                int col2 = min(n-1, j + K);
                
                res[i][j] = prefix[row2+1][col2+1] - prefix[row2+1][col1] - prefix[row1][col2+1] 
                    + prefix[row1][col1];
            }
        }
        return res;
    }
};