class Solution {
public:
    const vector<vector<int>> directions ={{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {1, 1}};
    vector<int> pondSizes(vector<vector<int>>& land) {
        vector<int> res;
        int m = land.size();
        int n = land[0].size();
        if(!m || !n) return res;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(land[i][j] == 0){
                    int size = dfs(land, i, j);
                    res.push_back(size);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
    int dfs(vector<vector<int>>& land, int i, int j){
        // in Area
        if(i < 0 || i >= land.size() || j < 0 || j >= land[0].size())
            return 0;
        // no recursion
        if(land[i][j] != 0){
            return 0;
        }
        land[i][j] = 1; // avoid repetition
        int size = 1;
        for(auto & d : directions){
            size += dfs(land, i+d[0], j+d[1]);
        }
        return size;
    }
};