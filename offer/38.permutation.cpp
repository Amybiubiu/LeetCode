class Solution {
private:
    set<string> res;
    vector<bool> used;
public:
    vector<string> permutation(string s) {
        int n = s.size();
        used = vector<bool>(n, false);
        string path = "";
        dfs(s, path);
        
        vector<string> premu;
        for(auto& item : res){
            premu.push_back(item);
        }
        return premu;
    }
    
    void dfs(string& s, string& path){
        if(path.size() == s.size()){
            res.insert(path);
            return;
        }
        for(int i = 0; i < s.size(); i++){
            if(!used[i]){
                used[i] = true;
                
                path.push_back(s[i]);
                dfs(s, path);
                
                used[i] = false;
                path.pop_back();
            }
        }
        return;
    }
};