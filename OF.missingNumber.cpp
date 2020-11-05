class Solution {
public:
    int res;
    int missingNumber(vector<int>& nums) {
        binarySearch(nums, 0, nums.size());
        return res;
    }
    
    void binarySearch(vector<int>& nums, int left, int right){
        if(left == right){
            res = left;
            return;
        }
        int mid = (left + right)/2;
        if(mid == nums[mid]){
            binarySearch(nums, mid + 1, right);
        }else{
            binarySearch(nums, left, mid);
        } 
        return;
    }
};
// 我居然把一个二分查找写成这样子也是很多余了

int missingNumber(int[] nums) {
        //二分查找的两种写法
//第一种
        int left = 0,right = nums.length-1;
        while(left <= right){
            int mid = (left + right)/2;
            if(nums[mid] == mid) {
                left = mid + 1;
            }else if(nums[mid] > mid){
                right = mid - 1;
            }
        }
        return left;
}