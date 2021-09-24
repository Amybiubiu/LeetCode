class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        dfs(candidates, target, 0, temp);
        return res;
    }

    void dfs(vector<int>& candidates, int sum, int start, vector<int>& path){
        if(sum == 0) {
            res.push_back(path);
            return;
        }else if(sum > 0){
            for(int i = start; i < candidates.size(); i++){
                path.push_back(candidates[i]);
                dfs(candidates, sum-candidates[i], i, path);
                path.pop_back();
            }
        }else{
            return;
        }
        return;
    }
};