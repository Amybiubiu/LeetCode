class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        vector<int> visit(n, 0);
        int count = 0;
        for(int i = 0; i < n; i++){
            if(!visit[i]){
                dfs(M, visit, i);
                count++;
            }
        }
        return count;
    }
    void dfs(vector<vector<int>>& M, vector<int>& visit, int i){
        visit[i] = 1;
        for(int j = 0; j < M.size(); j++){
            if(M[i][j] && !visit[j])
                dfs(M, visit, j);
        }
    }
};
