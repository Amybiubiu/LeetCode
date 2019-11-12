int uniquePaths(int m, int n){
    int path[n][m];
    int i;
    int j;
    for(i = 0;i<m;i++){
        path[0][i]=1;
    };
    for(j = 0;j<n;j++){
        path[j][0]=1;
    };
    for(i=1;i<m;i++){
        for(j=1;j<n;j++){
            path[j][i] = path[j-1][i] + path[j][i-1];
        }
    }
    return path[n-1][m-1];
}