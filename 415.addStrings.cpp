class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size()-1;
        int j = num2.size()-1;
        string res = "";
        int add = 0;
        while(i >= 0 || j >= 0 || add != 0){
            // 注意这里通过减法转为 int 的。
            int n1 = i >= 0 ? num1[i] - '0' : 0;
            int n2 = j >= 0 ? num2[j] - '0' : 0;
            int temp = n1 + n2 + add;
            // 同样也可以通过 + 将 int -》number
            res.push_back('0' + temp%10);
            
            --i;
            --j;
            add = temp/10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};