/**
 * @param {number[][]} obstacleGrid
 * @return {number}
 */
var uniquePathsWithObstacles = function(obstacleGrid) {
    var path = new Array();
    var n = obstacleGrid.length;//行数
    var m = obstacleGrid[0].length;//列数
    if(obstacleGrid[0][0] == 1)
        return 0;
    path[0] = new Array();
    path[0][0] = 1;
    for(var i = 1;i<n; i++){
        path[i] = new Array();
        if(obstacleGrid[i][0] == 1)
            path[i][0] = 0;  
        else
            path[i][0] = path[i-1][0];
            
    }
    for(var j = 1;j<m; j++){
        if(obstacleGrid[0][j] != 1){
            path[0][j] = path[0][j-1];
        }else
            path[0][j] = 0;
    }
    for(i = 1; i<n; i++){
        for(j = 1; j < m; j++){
            if(obstacleGrid[i][j] == 1)
                path[i][j] = 0;
            else
                path[i][j] = path[i-1][j] + path[i][j-1];
        }
    }
    console.log(path);
    return path[n-1][m-1];
};
var a =uniquePathsWithObstacles([[0,0],[1,1],[0,0]]);
console.log(a);