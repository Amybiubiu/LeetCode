class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) return {};
        int n = matrix[0].size();
        int total = m*n, cnt = 0;
        int top = 0, bottom = m-1, left = 0, right = n-1;
        vector<int> res;
        while(total){
            // to right
            for(int i = left; i <= right && total; i++){
                res.push_back(matrix[top][i]);
                total--;
                // cout<<"right"<<total<<endl;
            }
            top++;
            // to down
            for(int i = top; i <= bottom && total; i++){
                res.push_back(matrix[i][right]);
                total--;
                // cout<<"down"<<total<<endl;
            }
            right--;
            // to left
            for(int i = right; i >= left && total; i--){
                // 如果不加 total 的话，由于i 符合 left 和 right 的范围，total会变为-1；
                res.push_back(matrix[bottom][i]);
                total--;
                // cout<<"left"<<total<<endl;
            }
            bottom--;
            // to up
            for(int i = bottom; i >= top && total; i--){
                res.push_back(matrix[i][left]);
                total--;
                // cout<<"up"<<total<<endl;
            }
            left++;
        }
        return res;
    }
};