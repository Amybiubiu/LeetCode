class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        const int INF = 0x3f3f3f;
        vector<int> prices(n, INF);
        vector<int> backup(n);
        
        prices[src] = 0;
        for(int i = 0; i <= K; i++){
            backup.assign(prices.begin(), prices.end()); // 使k发挥约束作用
            for(auto &f : flights){
                prices[f[1]] = min(prices[f[1]], backup[f[0]]+ f[2]);
            }
        }
        
        if(prices[dst] == INF) return -1;
        return prices[dst];
    }
};
