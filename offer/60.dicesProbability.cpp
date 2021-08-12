/**
 * @param {number} n
 * @return {number[]}
 */
var dicesProbability = function(n) {
    var dp = [1.0/6.0, 1.0/6.0, 1.0/6.0, 1.0/6.0, 1.0/6.0, 1.0/6.0];
    for(let i = 2; i <= n; i++){
        // 从 i*1 到 i*6
        let temp = Array(5*i+1);
        temp.fill(0);
        for(let j = 0; j < dp.length; j++){
            for(let k = 0; k < 6; k++){
                temp[j+k] += dp[j]/6.0;
            }
        }
        dp = temp;
    }
    return dp;
};
