class Solution {
public:
    bool matchCore(string& s, string& p, int l, int r){
        // 理解为有限状态机
        if(s[l] == '\0' && p[r] == '\0')
            return true;
        if(s[l] != '\0' && p[r] == '\0')
            return false;
        // 对于 * 前面的元素是匹配还是不匹配的问题
        if(p[r+1] == '*'){
            // 当前的元素能够 match 
            if(s[l] == p[r] || (p[r] == '.' && s[l] != '\0'))
               // 保持当前状态
               return matchCore(s, p, l+1, r) 
               // 走入下一个状态
               || matchCore(s, p, l+1, r+2)
               // c* 作为空
               || matchCore(s, p, l, r+2);
            // 当前的元素不能 match
             else
               // c* 作为空
               return matchCore(s, p, l, r+2);
        }
        if(s[l] == p[r] || (p[r] == '.' && s[l] != '\0')){
            return matchCore(s, p, l+1, r+1);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        // if(s.empty() || p.empty())
        //     return false;
        return matchCore(s, p, 0, 0);
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        
        dp[0][0] = true;
        for(int i = 2; i < n+1; i+=2){
            dp[0][i] = dp[0][i-2] && p[i-1] == '*';
        }
        
        for(int i = 1; i < m+1; i++){
            for(int j = 1; j < n+1; j++){
                // 主要是考虑清楚，当前状态是由哪个状态转移而来的
                if(p[j-1] == '*'){
                    // 忽略c*
                    if(dp[i][j-2])
                        dp[i][j] = true;
                    // 匹配一次c*
                    else if(dp[i-1][j] && s[i-1] == p[j-2])
                        dp[i][j] = true;
                    // 匹配一次.*
                    else if(dp[i-1][j] && p[j-2] == '.')
                        dp[i][j] = true;
                }else{
                    // s p 各匹配一个
                    if(dp[i-1][j-1] && s[i-1] == p[j-1])
                        dp[i][j] = true;
                    // s p 各匹配一个
                    else if(dp[i-1][j-1] && p[j-1] == '.')
                        dp[i][j] = true;
                }
            }
        }
        return dp[m][n];
    }
};