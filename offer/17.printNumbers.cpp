class Solution {
public:
    // 剑指 offer 上要考虑大数问题
    vector<int> printNumbers(int n) {
        int num = 9;
        while(--n){
            num *= 10;
            num += 9;
        }
        vector<int> res(num, 0);
        for(int i = 0; i < num; i++){
            res[i] = i+1;
        }
        return res;
    }
};
class Solution {
public:
    int flag = 1;
    vector<int> res;
    vector<int> printNumbers(int n) {
        // cpp 中单引号和双引号居然是不同的
        string s = "0123456789";
        string str = "";
        dfs(s, str, n);
        return res;
    }
    void dfs(string& s, string& str, int n){
        if(str.size() == n){
            if(flag){
                flag = false;
                return;
            }
            res.push_back(atoi(str.c_str()));
            return ;
        }
        for(int i = 0; i < s.size(); i++){
            str += s[i];
            dfs(s, str, n);
            str.pop_back();
        }
    }
};