class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int cnt = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]){
                if(++cnt > n/2){
                    return nums[i];
                }
            }else{
                cnt = 1;
            }
        }
        return nums[n-1];
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};