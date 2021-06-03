class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l < r){
            while(l <= r && nums[l]%2){
                l++;
            }
            while(r >= 0 && nums[r]%2 == 0){
                r--;
            }
            if(l < r){
                int temp = nums[l];
                nums[l] = nums[r];
                nums[r] = temp;
                l++;
                r--;
            }
        }
        return nums;
    }
};