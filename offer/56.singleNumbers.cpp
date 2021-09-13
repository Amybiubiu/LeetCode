class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int x = 0, y = 0, m = 1, n = 0;
        for(auto num : nums)
            n ^= num;
        //  分组抑或，找最右1
        while((m&n) == 0)
            m <<= 1;
        // 最右1足以成为划分分组的规则
        for(auto num : nums){
            if((num&m) == 0)
                x^=num;
            else
                y^=num;
        }
        return {x,y};
    }
};