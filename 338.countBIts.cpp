class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1);   
        for(int i = 1; i <= num; i++){
            dp[i] = i%2?(dp[i-1]+1):dp[i/2];
        }
       
        return dp;
    }
};