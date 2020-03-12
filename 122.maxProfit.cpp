class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = prices.size();
        if(l== 0 || l== 1)
            return 0;
        vector<vector<int>> dp( 2, vector<int>(l));
        //理想买入金额
        dp[0][0] = prices[0];
        for(int i = 1; i < l; i++){
            if(prices[i] >= dp[0][i-1])
                dp[0][i] = dp[0][i-1];
            if(prices[i] < prices[i-1]){
                dp[0][i] = prices[i];
                dp[1][i-1] = prices[i-1] - dp[0][i-1];
            }
        }
        dp[1][l-1] = prices[l-1] - dp[0][l-1];
        return accumulate(dp[1].begin(), dp[1].end(), 0);
    }
};