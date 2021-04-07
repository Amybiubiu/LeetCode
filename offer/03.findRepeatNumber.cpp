class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            // 首先看这个数字是否在正确的索引上
            // 这样根本是不对的 不知道为什么为了测试 就诡异？？
            // 好诡异 刚把测试手动跑了一遍 用 if 写也是对的，只不过走的是另一条思路。
            // while 的话是把坑填好
            // if 是把萝卜填好
            if(nums[i] != i){
                // 再看这个数字的索引是否被占用，占用则是重复元素
                if(nums[nums[i]] == nums[i]){
                    return nums[i];
                }
                // 未被占用，归位
                int temp = nums[nums[i]];
                nums[nums[i]] = nums[i];
                nums[i] = temp;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int getCounts(vector<int>& nums, int l, int r){
        int c = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= l && nums[i] <= r){
                c++;
            }
        }
        return c;
    }
    int findRepeatNumber(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while(l < r){
            cout<<' '<<l<<' '<<r<<endl;
            int mid = (l+r)/2;
            // []
            int c = getCounts(nums, l, mid);
            // 数量等于不一定无重复 往左往右？？
            // 数量大于重复一定在里面，进左逼近
            // 数量小于 往右逼近？
            if(c > mid-l+1){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
    // 二分根本过不了测试用例 被坑了
    // [0, 1, 2, 0, 4, 5, 6, 7, 8, 9]
    // 0 9
    // 5 9
    // 8 9
};