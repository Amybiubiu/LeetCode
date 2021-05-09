class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        dfs(n, path, 1, k);
        return res;
    }
    void dfs(int n, vector<int>& path, int start, int k){
        if(path.size() == k){
            res.push_back(path);
            return;
        }
        for(int i = start; i <= n; i++){
            path.push_back(i);
            dfs(n, path, i+1, k);
            path.pop_back();
        }
    }
};