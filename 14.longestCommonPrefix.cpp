class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        if(strs.size() == 0 || strs[0] == "")
            return res;
        int r = 1;
        while(r <= strs[0].size()){
            string tmp = strs[0].substr(0, r);
            for(auto &s : strs){
                if(s.substr(0, r) != tmp)
                    return res;
            }
            res = tmp;
            r++;
        }
        return res;
    }
};