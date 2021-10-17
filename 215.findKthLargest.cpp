class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        quickSort(nums, k, 0, n - 1);
        return nums[n-k];
    }

    void quickSort(vector<int>& nums, int k, int l, int r){
        int n = nums.size();
        int t = nums[l];
        int i = l, j = r;

        while(i < j){
            while(i < j && nums[j] > t){
                j--;
            }
            if(i < j) nums[i++] = nums[j];

            while(i < j && nums[i] < t){
                i++;
            }
            if(i < j) nums[j--] = nums[i];
        }

        nums[i] = t;
        //cout<<"nums[n-k]"<<nums[n-k]<<"i"<<i<<endl;
        if(n-i == k) return;
        if(n-i > k)
            quickSort(nums, k, i+1, r);
        else
            quickSort(nums, k, l,i-1);
    }
};