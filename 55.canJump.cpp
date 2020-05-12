class Solution {
public:
    bool canJump(vector<int>& nums) {
        //只需要实时维护最远可到达 吐了 晚上真不适合写题 脑子根本转不动
        int n = nums.size();
        int rightmost = 0;
        for (int i = 0; i < n; ++i) {
            if (i <= rightmost) {
                rightmost = max(rightmost, i + nums[i]);
                if (rightmost >= n - 1) {
                    return true;
                }
            }
        }
        return false;
    }
};