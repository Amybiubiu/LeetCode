class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> dic;
        for(int i = 0; i < s.size(); i++){
            dic[s[i]]++;
        }
        for(auto& i : s){
            if(dic[i] == 1)
                return i;
        }
        return ' ';
    }
};