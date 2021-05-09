class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        dfs(nums, path, 0);
        return res;
    }
    void dfs(vector<int>& nums, vector<int>& path, int start){
        res.push_back(path);
        for(int i = start; i < nums.size(); i++){
            path.push_back(nums[i]);
            dfs(nums, path, i+1);
            path.pop_back();
        }
    }
};