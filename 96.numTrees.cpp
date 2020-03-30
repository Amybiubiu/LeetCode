class Solution {
    //好巧妙的数学数列啊
public:
    int numTrees(int n) {
        if(n==0) return 0;
        vector<int> dp(n+1);
        // int* dp = new int[n+1];
        // ?我指针瞎成这样了？这样也会
        // signed integer overflow: -1094795586 + -1094795584 cannot be represented in type 'int' 
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 0; j < i; j++){
                dp[i] += dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};

