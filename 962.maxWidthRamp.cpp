class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int n = A.size();
        if(n == 0)
            return 0;

        // 这个思路还可以用来做 leetcode 1124 好神奇
        vector<int> minl(n, 0);
        vector<int> maxr(n, 0);
        // 这道题目的思路对于我来说，还挺神奇的
        // 前缀最小值数组 后缀最大数组
        // minl(i) <= maxr(j) 则j-i一定是满足坡的
        // 且这个宽度是大于等于 j - i 的，因为 j 之后存在大于 i 之前的数。
        minl[0] = A[0];
        for(int i = 1; i < A.size(); i++){
            minl[i] = min(minl[i-1], A[i]);
        }
        maxr[n-1] = A[n-1];
        for(int i = n-2; i >= 0; i--){
            maxr[i] = max(maxr[i+1], A[i]);
        }
        cout<<endl;
        int i = 0, j = 0;
        int res = 0;
        while(i < n && j < n){
            cout<<i<<' '<<j<<endl;
            if(minl[i] <= maxr[j]){
                res = max(res, j-i);
                j++;
            }else{
                i++;
            }
        }
        return res;
    }
};