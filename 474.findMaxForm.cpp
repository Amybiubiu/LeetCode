// class Solution {
// public:
//     int findMaxForm(vector<string>& strs, int m, int n) {
//         vector<vector<int>> dp(m+1,vector<int>(n+1,0));
//         for(int i = 0; i < strs.size(); i++){
//             vector<int> count = caculate(strs[i]);
//             for(int zeros = m; m >= count[0]; m--){
//                 for(int ones = n; n >= count[1]; n--){
//                     dp[zeros][ones] = max(1+dp[zeros-count[0]][ones-count[1]], dp[zeros][ones]);
//                 }
//             }
//         }
//         return dp[m][n];
//     }
//     vector<int> caculate(string s){
//             vector<int> count(2, 0);
//             for(int i = 0; i < s.size(); i++)
//             {
//                 if(s[i]=='0')
//                    count[0]++;
//                 else
//                     count[1]++;
//             }
//         return count;
//     }
// };
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int S = strs.size();
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
        for (int l = 0; l < S; ++l) {
            int zero = 0;
            int one = 0;
            for (int i = 0; i < strs[l].size(); ++i) {
                if (strs[l][i] == '0') ++zero;
                else ++one;
            }
            for (int i = m; i >= zero; --i) {
                for (int j = n; j >= one; --j) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zero][j - one]);
                }
            }
        }
        return dp[m][n];
    }
};




