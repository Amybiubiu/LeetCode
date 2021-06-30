class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> position(128, -1);
        int curLength = 0;
        int maxLength = 0;
        for(int i = 0; i < s.size(); i++){
            int pre = position[s[i]];
            if(pre == -1 || i - pre > curLength)
                curLength += 1;
            else
                curLength = i - pre;
            maxLength = max(maxLength, curLength);
            position[s[i]] = i;
        }
        return maxLength;
    }
};