class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n; // 防溢出
        for(int i = 0; i < n/2; i++){
            swap(nums[i], nums[n-1-i]);
        }
        // 对 k 检查 i 是否溢出访问区间
        for(int i = 0; i < k/2; i++){
            // 像 k-1-i 这种一定要查看是否溢出
            swap(nums[i], nums[k-1-i]);
        }
        for(int i = 0; i < (n-k)/2; i++){
            swap(nums[i+k], nums[n-1-i]);
        }
    }
};