class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        int high = n/10;
        int cur = n%10;
        int low = 0;
        long digit = 1;
        while(cur || high){
            switch(cur){
                case 0:
                    res += high*digit;
                    break;
                case 1:
                    res += high*digit + low + 1;
                    break;
                default:
                    res += (high+1)*digit;
            }
            
            low = low + cur*digit;
            cur = high%10;
            high = high/10;
            digit *= 10;
        }
        return res;
    }
};