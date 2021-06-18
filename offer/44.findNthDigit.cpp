class Solution {
public:
    int findNthDigit(int n) {
        // int total = 1;
        long long start = 1;
        int digit = 1;
        long long count = 9*digit*start;
        while(n > count){
            n -= count;
            start *= 10;
            digit += 1;
            count = 9*digit*start;
        }
        int num = start + (n-1)/digit;
        string s = to_string(num);
        return s[(n-1)%digit] - '0';
    }
};