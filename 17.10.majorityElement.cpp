class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0];
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(count == 0){
                ans = nums[i];
                count = 1;
            }else{
                count = (nums[i] == ans)?count + 1 : count-1;
            }
        }
        if(count <= 0) return -1;
        int amount = 0;
        for(auto i : nums){
            if(i == ans)
                amount++;
        }
        return amount > nums.size()/2 ? ans : -1;
    }
};