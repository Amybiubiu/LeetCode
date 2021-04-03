function getMAx(arr, k){
    let n = arr.length;
    let res = 0;
    let dp = Array(n+1);
    dp[0] = 0;
    for(let i = 0; i < n; i++){
        dp[i] = arr[i] > 0 ? dp[i-1] + dp[i] : dp[i-1];
        res = Math.max(dp[i], res);
    }
}
let arr = [-1, 3, 4, 7, 2, -6, 3, 4];
let k = 3;
console.log(getMax(arr, k));