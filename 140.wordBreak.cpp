class Solution {
public:
    int total = 1;
    static const int N = 100010;
    int trie[N][26] = {0};
    int end[N] = {0};
    void insert(const char* str){
        int p = 0;    // 从1开始，因为后面要 check 指向是否为 0；x 因为指向的是 next 所以可以从 0 开始
        for(int i = 0; i < strlen(str); i++){
            int ch = str[i] - 'a';
            if(trie[p][ch] == 0){
                trie[p][ch] = ++total;
            }
            p = trie[p][ch];
        }
        end[p]++;
    }
    int search(const char* str){
        int p = 0;
        for(int i = 0; i < strlen(str); i++){
            int ch = str[i] - 'a';
            p = trie[p][ch];
            if(!p) return 0;
        }
        return end[p];
    }
    void dfs(string& s, vector<string> path){
        int start = 0;
        for(int i = 0; i < path.size(); i++){
            start += path[i].size();
        }
        if(start == s.size()){
            // 语法🍬有无？
            string sentence = "";
            int n = path.size();
            for(int i = 0; i < n - 1; i++){
                sentence += path[i];
                sentence += " ";
            }
            sentence += path[n-1];
            res.push_back(sentence);
        }
        for(int i = start; i < s.size(); i++){
            string sub = s.substr(start, i - start + 1);
            // 感觉可以参考 472 那道题，把 substr 干掉。
            if(search(sub.c_str()) == 1){
                path.push_back(sub);
                dfs(s, path);
                path.pop_back();
            }
        }
    }
    vector<string> res;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // memset(trie, 0, sizeof trie);
        // memset(end, 0, sizeof end);
        for(int i = 0; i < wordDict.size(); i++){
            string str = wordDict[i];
            // if(i > 0)
            //     cout<<"search: "<<search(wordDict[i-1].c_str())<<endl;
            insert(str.c_str());
        }
        vector<string> path;
        dfs(s, path);
        return res;
    }
};