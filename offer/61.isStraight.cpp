class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int i = 0, n = nums.size();
        while(i < n && nums[i]==0){
            count++;
            i++;
        }
        for(; i < n; i++){
            // cout<<"num"<<nums[i]<<endl;
            if(i == 0 || i == count)
                continue;
            int subtract = nums[i] - nums[i-1]-1;
            // cout<<"subtract"<<subtract<<endl;
            if(subtract > 0 ){
                count -= subtract;
            }else if(subtract < 0){
                return false;
            }
            if(count < 0)
                return false;
        }
        return true;
    }
};