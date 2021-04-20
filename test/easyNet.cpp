class Solution {
private:
    unordered_map<char, int> map;
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param charList char字符型vector 上述C字符集合，集合大小不大于10，不重复
     * @param s string字符串 上述字符串s，长度不大于100000
     * @return int整型
     */
    bool isOdd(){
        for(auto& i : map){
            if(i.second%2){
                return false;
            }
        }
        return true;
    }
    int maxSubStrLength(vector<char>& charList, string s) {
        // write code here
        for(auto& i : charList){
            map[i] = 0;
        }
        int n = s.size();
        vector<int> dp(n+1, 0);
        for(int i = 0; i < n; i++){
            if(map[s[i]]){
                map[s[i]]++;
                if(isOdd()){
                    dp[i+1] = i+1;
                }else{
                    dp[i+1] = dp[i];
                }
            }else{
                if(isOdd()){
                    dp[i+1] = dp[i]+1;
                }else{
                    dp[i+1] = dp[i];
                }
            }
        }
        return dp[n];
    }
};