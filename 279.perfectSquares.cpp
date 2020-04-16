//暴力递归，当然超时了
class Solution {
public:
    int numSquares(int n) {
        int ra = 1;
        while(ra*ra <= n){
            ra++;
        }
        if((ra-1)*(ra-1) == n)
            return 1;
        int min=n;
        for(int i = (ra-1); i > 0; i--){
            int temp = numSquares(n-i*i);
            min = temp < min?temp:min;
        }
        return min+1;
    }
};
//动态规划
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        for(int i = 1; i<=n; i++){
            dp[i] = i;
            for(int j = 1; i-j*j >=0; j++){
                dp[i] = min(dp[i],dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};