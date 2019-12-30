class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        for(int i = 1;i<nums.size();i++){
            res = res^nums[i];
        }
        return res;
    }
    //位操作真的牛逼，最开始想到的建立一个哈希表
    // 后面对于空间的要求，考虑用先进排序，可是不想写快排，不熟练呃呃呃
};