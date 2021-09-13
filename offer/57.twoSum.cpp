class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        int sum = 0;
        while(l < r){
            sum = nums[l] + nums[r];
            if(sum == target)
                return {nums[l], nums[r]};
            if(sum < target){
                l++;
            }else
                r--;
        }
        return {};
    }
};