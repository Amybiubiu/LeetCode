class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 目标数字出现的次数之和大于其它元素此数之和
        // 有点巧妙
        int res;
        int times = 0;
        for(int i = 0; i < nums.size(); i++){
            if(times == 0){
                res = nums[i];
                times = 1;
            }else{
                // 抵消or消耗
                times = nums[i] == res ? ++times : --times;
            }
        }
        return res;
    }
};