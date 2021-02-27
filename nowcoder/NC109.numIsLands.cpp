class Solution {
public:
    /**
     * 判断岛屿数量
     * @param grid char字符型vector<vector<>> 
     * @return int整型
     */
    int res = 0;
    bool inArea(vector<vector<char>>& grid, int i, int j){
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
    }
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(inArea(grid, i, j) && grid[i][j] == '1'){
          grid[i][j] = '0';
          dfs(grid, i-1, j);
          dfs(grid, i, j-1);
          dfs(grid, i, j+1);
          dfs(grid, i+1, j);  
        }
    }
    int solve(vector<vector<char>>& grid) {
        // write code here
        int m = grid.size();
        int n = grid[0].size();
        if(!m || !n) return 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    } 
};
class Solution {
public:
    /**
     * 判断岛屿数量
     * @param grid char字符型vector<vector<>> 
     * @return int整型
     */
    int res = 0;
    bool inArea(<vector<vector<char>>& grid, int i, int j){
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
    }
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(!inArea(grid, i, j)) return;
        grid[i][j] = '0';
        dfs(grid, i-1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
        dfs(grid, i+1, j);
    }
    int solve(vector<vector<char>>& grid) {
        // write code here
        int m = grid.size();
        int n = grid[0].size();
        if(!m || !n) return 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    } 
};
// 编译错误:您提交的代码无法完成编译
// In file included from main.cc:2:
// ./solution.h:9:17: error: expected parameter declarator
// bool inArea(<vector<vector<char>>& grid, int i, int j){
// ^
// ./solution.h:9:17: error: expected ')'
// ./solution.h:9:16: note: to match this '('
// bool inArea(<vector<vector<char>>& grid, int i, int j){
// ^
// ./solution.h:10:30: error: use of undeclared identifier 'grid'
// return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
// ^
// ./solution.h:10:26: error: use of undeclared identifier 'i'
// return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
// ^
// ./solution.h:10:16: error: use of undeclared identifier 'i'
// return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
// ^
// ./solution.h:10:45: error: use of undeclared identifier 'j'
// return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
// ^
// ./solution.h:10:59: error: use of undeclared identifier 'grid'
// return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
// ^
// ./solution.h:10:55: error: use of undeclared identifier 'j'
// return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
// ^
// ./solution.h:13:20: error: too many arguments to function call, expected 0, have 3
// if(!inArea(grid, i, j)) return;
// ~~~~~~ ^~~~~~~~~~
// ./solution.h:9:10: note: 'inArea' declared here
// bool inArea(<vector<vector<char>>& grid, int i, int j){
// ^
// 9 errors generated.