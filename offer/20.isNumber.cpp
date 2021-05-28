class Solution {
public:
    bool isUnsignedInt(string s, int& pos){
        int start = pos;
        while(pos != s.size() && s[pos] >= '0' && s[pos] <= '9'){
            pos++;
        }
        // cout<<pos<<endl;
        return pos > start;
    }
    bool isInt(string s, int& pos){
        if(s[pos] == '+' || s[pos] == '-'){
            pos++;
        }
        return isUnsignedInt(s, pos);
    }
    bool isNumber(string s) {
        
        int pos = 0;
        while(s[pos] == ' '){
            pos++;
        }
        // 关于不断去判断是否合法设置一个 numberic 变量
        bool numberic = isInt(s, pos);
        if(s[pos] == '.'){
            pos++;
            numberic = isUnsignedInt(s, pos) || numberic;
        }
        if(s[pos] == 'e' || s[pos] == 'E'){
            pos++;
            numberic = numberic && isInt(s, pos);
        }
        while(s[pos] == ' '){
            pos++;
        }
        // cout<<pos<<endl;
        return numberic && pos == s.size();
    }
};