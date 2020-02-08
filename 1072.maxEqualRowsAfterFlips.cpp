class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> m;
        int res = 0;
        for(auto row : matrix){
            string s;
            int o = row[0]^1;
            for(auto i : row){
                s += i^o + '0';
            };
            ++m[s];
            res = max(res,m[s]);
        }
        return res;
    }
};
