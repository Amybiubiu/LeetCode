class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(dfs(board, i, j, word, 0)){
                    return true;
                }
            }
        }
        return false;
    }
private:
    int n;
    int m;
    bool dfs(vector<vector<char>>& board, int i, int j, string word, int t){
        if(i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word[t]){
            return false;
        }
        if(t == word.size() - 1) return true;
        board[i][j] = '\0';
        bool res = dfs(board, i-1, j, word, t+1) || dfs(board, i+1, j, word, t+1)
            || dfs(board, i, j-1, word, t+1) || dfs(board, i, j+1, word, t+1);
        board[i][j] = word[t];
        return res;
    }
};