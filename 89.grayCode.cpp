class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res(1<<n);
        res[0]=0;
        for(int i=1;i< 1<<n;i++){
            res[i] = i^(i>>1);
        }
        return res;
    }
};