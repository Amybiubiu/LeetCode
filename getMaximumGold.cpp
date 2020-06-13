class Solution {
public:
    int m,n;
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        if(m == 0) return 0;
        n = grid[0].size();
        int res = 0,i,j;
        for(i = 0;i < m;i++){
            for(j = 0;j < n;j++){
                if(grid[i][j] != 0){
                    res = max(res,dfs(grid,i,j,0));
                }
            }
        }
        return res;
    }
    //为什么加 & 原地操作不会超时,而不加 & 就会超时？
    //先欠着 到时候熟悉汇编之后再看看机器代码上的差别
    int dfs(vector<vector<int> >& grid,int i,int j,int sum){
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
            return sum;
        int temp = grid[i][j];
        grid[i][j] = 0;
        int a = dfs(grid,i + 1,j,sum + temp);
        int b = dfs(grid,i,j + 1,sum + temp);
        int c = dfs(grid,i - 1,j,sum + temp);
        int d = dfs(grid,i,j - 1,sum + temp);
        grid[i][j] = temp;
        return max(max(a,b),max(c,d));
    }
    //无论如何 都要自己动手敲啊
};
