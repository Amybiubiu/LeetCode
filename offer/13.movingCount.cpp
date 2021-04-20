class Solution {
private:
    int r;
    int c;
public:
    int getDigitSum(int num){
        int sum = 0;
        while(num>0){
            int a = num%10;
            num = num/10;
            sum += a;
        }
        return sum;
    }
    int movingCount(int m, int n, int k) {
        r = m;
        c = n;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return dfs(0, 0, k, visited);
    }
    int dfs(int i, int j, int k, vector<vector<bool>>& visited){
        if( i < 0 || i >= r || j < 0 || j >= c || getDigitSum(i) + getDigitSum(j) > k || visited[i][j]){
            return 0;
        }
        int count = 1;
        visited[i][j] = true;
        count = count + dfs(i+1, j, k, visited) + dfs(i-1, j, k, visited)
            + dfs(i, j+1, k, visited) + dfs(i, j-1, k, visited);    // 此处可以优化 只向下和向右
        return count;
    }
};