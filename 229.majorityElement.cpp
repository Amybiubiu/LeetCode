class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int cand1 = nums[0], cand2 = nums[0];
        int count1 = 0, count2 = 0;
        // 配对阶段
        for (int num : nums) {
            // 投票
            if (cand1 == num) {
                count1++;
                continue;
            }
            if (cand2 == num) {
                count2++;
                continue;
            }

            // 第1个候选人配对
            if (count1 == 0) {
                cand1 = num;
                count1++;
                continue;
            }
            // 第2个候选人配对
            if (count2 == 0) {
                cand2 = num;
                count2++;
                continue;
            }

            count1--;
            count2--;
        }

        // 计数阶段
        // 找到了两个候选人之后，需要确定票数是否满足大于 N/3
        count1 = 0;
        count2 = 0;
        for (int num : nums) {
            if (cand1 == num) count1++;
            else if (cand2 == num) count2++;
        }

        if (count1 > nums.size() / 3) res.push_back(cand1);
        if (count2 > nums.size() / 3) res.push_back(cand2);

        return res;
    }
};