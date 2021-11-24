class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        string str = "";
        dfs(str, n, n);
        return res;
    }
    void dfs(string path, int l, int r){
        if(l == 0 && r == 0){
            res.push_back(path);
            return;
        }
        if(l < 0 || r < l) return;
        dfs(path+ '(', l-1, r);
        dfs(path+ ')', l, r-1);
    }
};