class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        for(int i = 0; i < m; i++){
            int _min = INT_MAX;
            for(int j = 0; j < n; j++){
                _min = min(_min, matrix[i][j]);
            }
            row[i] = _min;
        }
        for(int j = 0; j < n; j++){
            int _max = INT_MIN;
            for(int i = 0; i < m; i++){
                _max = max(_max, matrix[i][j]);
            }
            col[j] = _max;
        }
        vector<int> res;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                // if(matrix[i][j] == row[i] && matrix[i][j] == col[j]){
                // 无重复！！
                if(row[i] == col[j])
                    res.push_back(row[i]);
                // }
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row(m, 10001);
        vector<int> col(n, 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                row[i] = min(row[i], matrix[i][j]);
                col[j] = max(col[j], matrix[i][j]);
            }
        }
        vector<int> res;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                // if(matrix[i][j] == row[i] && matrix[i][j] == col[j]){
                // 无重复！！
                if(row[i] == col[j])
                    res.push_back(row[i]);
                // }
            }
        }
        return res;
    }
};