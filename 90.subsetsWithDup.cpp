class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> path;
        res.push_back(path);
        
        solve(res,nums,path,0);
        return res;
    }
    void solve(vector<vector<int>>& res,vector<int> nums,vector<int> path,int s){
        for(int i=s;i<nums.size();i++){
            if(i>s && nums[i] == nums[i-1])
                continue;
            
            path.push_back(nums[i]);
            res.push_back(path);

            solve(res,nums,path,i+1);
            path.pop_back();
        }
    }
};