class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return;
        int i = 0;
        int p1 = 0;
        int p2 = n-1;
        
        while(i <= p2){
            if(nums[i] == 0){
                swap(nums[i], nums[p1]);
                p1++;
                i++;
            }else if(nums[i] == 1){
                i++;
            }else if(nums[i] == 2){
                swap(nums[i], nums[p2]);
                p2--;
            }
        }
    }
};