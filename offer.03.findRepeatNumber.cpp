class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, int> map(nums.size());
        for(auto &i : nums){
            map[i]++;
            if(map[i] > 1)
                return i;
        }
        return -1;
    }
};