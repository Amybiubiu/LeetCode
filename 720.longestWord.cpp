class Solution {
public:
    string longestWord(vector<string> &words) {
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() != b.size() ? a.size() < b.size() : a > b;
        });
        string longest;
        unordered_set<string> candidates = {""};
        for (const auto &word: words) {
            if (candidates.count(word.substr(0, word.size() - 1))) {
                candidates.emplace(word);
                longest = word;
            }
        }
        return longest;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        
        sort(words.begin(), words.end(), [](string a, string b){ return a.size() < b.size();});
        unordered_map<string, bool> map;
        map[""] = true;
        for(int i = 0; i < words.size(); i++){
            int len = words[i].size();
            string pre = words[i].substr(0, len-1);
            if(map.count(pre)){
                // cout<<"word:"<<words[i]<<endl;
                map[words[i]] = true;
            }
        }
        vector<string> list;
        for(auto it = map.begin(); it != map.end(); it++){
            list.push_back(it->first);
        }
        if(list.size() == 1) return "";
        sort(list.begin(), list.end(), [](string a, string b){ return a.size() > b.size();});
        if(list[1].size() < list[0].size()) return list[0];
        string les = list[0];
        int i = 1;
        while(list[i].size() == list[0].size()){
            if(list[i] < les){
                les = list[i];
            }
            i++;
        }
        return les;
    }
};