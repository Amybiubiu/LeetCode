class Solution {
public:
    /**
     * max sum of the subarray
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxsumofSubarray(vector<int>& arr) {
        // write code here
        int n = arr.size();
        if(!n) return 0;
        vector<int> dp(n+1);
        int res = 0;
        for(int i = 0; i < n; i++){
            dp[i+1] = max(dp[i]+arr[i], arr[i]);
            res = max(dp[i+1], res);
        }
        return res;
    }
};