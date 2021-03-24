class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<int> temp(nums.size());
        return mergeSort(nums, temp, 0, nums.size() - 1);
    }
    int mergeSort(vector<int> nums, vector<int> temp, int l, int r){
        if(r <= l)
            return 0;
        int mid = (l+r)/2;
        int res = mergeSort(nums, temp, l, mid) +  mergeSort(nums, temp, mid+1, r);
       
        
        int i = l;
        int j = mid + 1;
        int pos = l;
        while( i <= mid && j <= r){
            if(nums[i] <= nums[j]){
                temp[pos++] = nums[i++];
                res += (j - (mid + 1));
            }else{
                temp[pos++] = nums[j++];
            }
        }
        while(i <= mid){
            temp[pos++] = nums[i++];
            res += (j - (mid + 1));
        }
        while(j <= r){
            temp[pos++] = nums[j++];
        }
        copy(temp.begin() + l, temp.begin() + r + 1, nums.begin() + l);
        return res;
    }
};