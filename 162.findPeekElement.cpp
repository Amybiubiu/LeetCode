class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //二分搜索递归找最大值，泪了
        return binary_search(nums,0,nums.size()-1);
    }
    
    int binary_search(vector<int> nums,int left,int right){
        if(left == right)
            return left;
        int mid = (left+right)/2;
        if(nums[mid]>nums[mid+1])
            return binary_search(nums,left,mid);
        return binary_search(nums,mid+1,right);
    }
};