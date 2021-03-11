class Solution {
public:
    int fresh = 0;
    int round = 0;
    queue<pair<int, int>> q;
    int orangesRotting(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1)
                    fresh++;
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while(!q.empty()){
            int size = q.size();
            int rotten = false;
            // 在 while 中放一层主要是时间计算的原因 在别的多源 BFS 一般不要这层 for
            for(int i = 0; i < size; i++){
                pair<int, int> node = q.front();
                q.pop();
                for(auto & d : dir){
                    int x = node.first + d.first;
                    int y = node.second + d.second;
                    // 应该只把周围新鲜的橘子加入队列，腐烂的已经处理带坏了别的橘子出队列了
                    if( x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 1){
                        q.push({x, y});
                        grid[x][y] = 2;
                        fresh--;
                        rotten = true;
                    }
                }
            }
            // 设置rotten的原因是如果一个橘子周围全部腐烂，遍历周围的结果仍旧腐烂，实则不应该存在时间消耗
            if(rotten) round++;
        }
        
        return fresh ? -1 : round;
    }
};


