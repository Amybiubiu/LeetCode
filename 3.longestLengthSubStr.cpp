class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> set;
        int res = 0;
        int l = 0;
        int r = 0;
        while(r < s.size()){
            // 这里是用 while 循环向右移动
            while(set.find(s[r]) != set.end()){
                set.erase(s[l]);
                l++;
            }
            set.insert(s[r]);
            res = max(res, r-l+1);
            r++;
        }
        return res;
    }
};