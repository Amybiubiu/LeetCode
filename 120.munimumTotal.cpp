class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>> dp(m, vector<int>(n));
        for(int i = 0; i < triangle.size(); i++){
            for(int j = 0; j < triangle[i].size(); j++){
                if(i == 0 && j == 0)
                    dp[i][j] = triangle[i][j];
                else if(j == 0 )
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                else if(j == triangle[i].size()-1)
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                else
                    dp[i][j] = min(dp[i-1][j-1],dp[i-1][j]) + triangle[i][j];
            }
        }
       return *std::min_element(dp[m-1].begin(), dp[m-1].end() ) ;
    }
};
//         int rowSize = triangle.size();
//         vector<vector<int>> dp(triangle);
                
//         for(int i=rowSize-2;i>=0;i--) {        
//             for(int j=0; j<triangle[i].size(); j++) {
//                 dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
//             }
//         }
//         return dp[0][0];
