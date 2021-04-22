class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        unsigned flag = 1;
        for(int i = 0; i < 32; i++){
            if(n&flag){
                res++;
            }
            flag = flag<<1;
        }
        return res;
    }
};