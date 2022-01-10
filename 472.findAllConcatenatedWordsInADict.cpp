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
                trie[p][ch] = total++;
            }
            p = trie[p][ch];
        }
        end[p]++;
    }
    // int search(const char* str){
    //     int p = 0;
    //     for(int i = 0; i < strlen(str); i++){
    //         int ch = str[i] - 'a';
    //         p = trie[p][ch];
    //         if(!p) return 0;
    //     }
    //     return end[p];
    // }
    unordered_map<int, unordered_map<int, int>> map;
    int dfs(string& s, int word, int pos){
        if(map[word][pos] == 1) return 0;
        if(pos >= s.size()){
            res.push_back(s);
            return 1;
        }
        int p = 0;
        for(int i = pos; i < s.size(); i++){
            int ch = s[i] - 'a';
            if(trie[p][ch] == 0) {
                break;
            }
            p = trie[p][ch]; // 这个必须要写在 end[p] 前面，但是我还没有理清楚
            // 我知道了！
            // 数组模拟树
            //    0
            //   a   b   c  d
            //  1  2
            // a b
            //3
            //p 只是 1，2，3，4；类比指针，指针只存储地址，p->val 才是实际的值
            //trie[p][ch] 才是代表字符
            if(end[p]){
                if(dfs(s, word, i+1)){
                    return 1;
                }
            }
        }
        // for(int i = start; i < s.size(); i++){
        //     string sub = s.substr(start, i - start + 1); // substr 非常耗时，在 for 循环用一次，优化直接白搭
        //     if(search(sub.c_str()) == 1){
        //         if(dfs(s, word, i+1) == 1){
        //             return 1;
        //         }
        //     }
        // }

        map[word][pos] = 1;
        return 0;
    }
    vector<string> res;
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& a, string& b){
            return a.size() < b.size();
        });
        for(int i = 0; i < words.size(); i++){
            if(words[i].size() == 0) continue;
            if(dfs(words[i], i, 0) == 0){
                insert(words[i].c_str());
            }
        }
        return res;
    }
};