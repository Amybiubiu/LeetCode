class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        switch(n){
            case 0:
                return 0;
            case 1:
                return 1;
            default:
                res.push_back(nums[0]);
                if(nums[1] != nums[0])
                    res.push_back(nums[1]);
                if(n == 2)
                    return res.size();
        }
        
        for(int i = 2; i < n; i++){
            if(nums[i-1]==nums[i-2] && nums[i]!= nums[i-1]){
                res.push_back(nums[i]);
                continue;
            }
            if( (nums[i]-nums[i-1])*(nums[i-1]-nums[i-2])<0)
                res.push_back(nums[i]);
        }
        return res.size();
    }
};
// 25/27 output: 336 expect：334 这种怎么debug 哭晕在厕所
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return n;
        int prevdiff = nums[1] - nums[0];
        int count = prevdiff != 0 ? 2 : 1;
        for (int i = 2; i < n; i++) {
            int diff = nums[i] - nums[i - 1];
            if ((diff > 0 && prevdiff <= 0) || (diff < 0 && prevdiff >= 0)) {
                count++;
                prevdiff = diff;
            }
        }
        return count;
    };
};
//在我看来上面这两种分类是一致的 不知道怎么就fail了 除了第一个switch实在太丑了
//差别在于只有count加一时候才更新prediff 可是这在那些非加一的情况都不会影响计数啊
//有情况会影响计数变多eg: pre > 0 diff = 0 next > 0 