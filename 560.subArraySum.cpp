class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // 这题的思路可以用来做 1248
        unordered_map<int, int> map;
        int total = 0;
        int res = 0;
        map[0] = 1;
        for(auto& x : nums){
            total += x;
            res += map[total - k];
            // cout<<"map:"<<map[total - k]<<" ";
            map[total]++;
        }
        return res;
    }
};