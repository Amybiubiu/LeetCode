// const int N = 1000010;
// int son[N][26], cnt[N], idx;
class Trie {
private:
    int son[100010][26] = {0};
    int cnt[100010] = {0};
    int idx = 0;
public:
    /** Initialize your data structure here. */
    Trie() {
        // son.memset(son, 0, sizeof(son));
        // cnt.memset(cnt, 0, sizeof(cnt));
        // idx = 0;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int p = 0;
        for(int i = 0; i < word.size(); i++){
            int s = word[i] - 'a';
            if(!son[p][s]){
                son[p][s] = ++idx;
            }
            p = son[p][s];
        }
        cnt[p]++;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int p = 0;
        for(int i = 0; i < word.size(); i++){
            int s = word[i] - 'a';
            if(!son[p][s]){
                return false;
            }
            p = son[p][s];
        }
        if(cnt[p]){
            return true;
        }else{
            return false;
        }
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int p = 0;
        for(int i = 0; i < prefix.size(); i++){
            int s = prefix[i] - 'a';
            if(!son[p][s]){
                return false;
            }
            p = son[p][s];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */