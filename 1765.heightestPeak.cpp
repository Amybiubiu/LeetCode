class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> res(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        for(int i = 0; i < isWater.size(); i++){
            for(int j = 0; j < isWater[0].size(); j++){
                if(isWater[i][j]){
                     q.push({i ,j});
                     res[i][j] = 0;
                }
            }
        }
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!q.empty()){
                pair<int, int> node = q.front();
                q.pop();
                for(auto d : dir){
                    int x = node.first + d.first;
                    int y = node.second + d.second;
                    if( x >= 0 && y >= 0 && x < isWater.size() && y < isWater[0].size() && res[x][y] == -1)
                    {
                        res[x][y] = res[node.first][node.second] + 1;
                        q.push({x, y});
                    }
                }
        }
        return res;
    }
};