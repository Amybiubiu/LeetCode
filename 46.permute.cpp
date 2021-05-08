class Solution {
private:
    vector<vector<int>> res;
    vector<bool> isUsed;
public:
    void dfs(vector<int>& nums, vector<int>& temp, int k){
        int n = nums.size();
        if(k == n){
            res.push_back(temp);
            return;
        }
        for(int i = 0; i < n; i++){
            if(!isUsed[i]){
                temp[k] = nums[i];
                isUsed[i] = true;
                dfs(nums, temp, k+1);
                isUsed[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        if(!n)
            return res;
        isUsed.resize(n);
        for(int i = 0; i < n; i++){
            isUsed[i] = false;
        }
        vector<int> temp(n);
        dfs(nums, temp, 0);
        return res;
    }
};