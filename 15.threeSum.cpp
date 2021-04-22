class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        if(n < 3){
            return res;
        }
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
               return res;
            }
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int l = i+1;
            int r = n-1;
            while(l < r){
                if(nums[i] + nums[l] + nums[r] == 0){
                    res.push_back({nums[i],nums[l],nums[r]});
                    // 不用 l r 控制的话 可能会移越界
                    while(l < r && nums[l] == nums[l+1]){
                        l++;
                    }
                    while(l < r && nums[r] == nums[r-1]){
                        r--;
                    }
                    l++;
                    r--;
                }else if(nums[i] + nums[l] + nums[r] > 0){
                    r--;
                }else{
                    l++;
                }
            }
        }
        return res;
    }
};