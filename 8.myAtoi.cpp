class Solution {
public:
    int myAtoi(string s) {
        int num = 0;
        // 查 0
        int i = 0;
        int sign = 1;
        while(s[i] == ' '){
            i++;
        }
        // 处理 + -
        if(s[i] == '+' || s[i] == '-'){
            sign = -1 + 2 * (s[i++] == '-' ? 0 : 1);
        }
        // 得 num
        while(s[i] >= '0' && s[i] <= '9'){
            if(num > INT_MAX / 10 || (num == INT_MAX/10 && s[i] - '0' > 7)){
                return sign > 0 ? INT_MAX : INT_MIN;
            }
            
            num = num*10 + (s[i++] - '0');
        }
        return num*sign;
    }
};