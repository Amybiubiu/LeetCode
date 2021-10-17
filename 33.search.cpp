class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;// !
        while(l < r){
            int mid = (l+r+1)>>1; // 会相遇吗？ l = mid (l+r+1)
            
                bool left_i = nums[l] < nums[mid];
                if(left_i){
                    if(target >= nums[mid] || target < nums[l]){
                        l = mid;
                        cout<<"1"<<endl;
                    }else{
                        r = mid - 1;
                        cout<<"2"<<endl;
                    }
                }else{
                    if(target > nums[r] || target < nums[mid]){
                        r = mid-1;
                        cout<<"3"<<endl;
                    }else{
                        l = mid;
                        cout<<"4"<<endl;
                    }
                }
        }
        if(nums[l] == target) return l;
        return -1;
    }
};