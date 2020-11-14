class Solution {
public:
    int hIndex(vector<int>& citations) {
        int length = citations.size();
        if(!length) return 0;
        return binarySearch(citations, 0, length-1);
    }
    int binarySearch(vector<int>& nums, int left, int right){
       
        int n = nums.size();
        if(left > right)
            return n - left;
        int mid = (left + right)/2;
        if(n-mid == nums[mid])
            return n - mid;
        else if(n - mid < nums[mid]){
            return binarySearch(nums, left, mid - 1);
        }else{
            return binarySearch(nums, mid+1, right);
        }
       
    }
};