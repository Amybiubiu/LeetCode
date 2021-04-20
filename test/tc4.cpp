class Solution {
private:
    unordered_map<char, int> map;
    string S;
    vector<char> CharList;
    int res;
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
    bool init(){
        for(auto& i : CharList){
            map[i] = 0;
        }
    }
    void helper(int i, int j){
        if(i >= j){
            return;
        }
        for(int k = i; k <= j; k++){
            if(map[S[k]]){
                 map[S[k]]++;
            }
        }
            if(isOdd()){
                res = max(res, (j-i+1));
            }else{
                map.clear();
                init();
                helper(i+1, j);
                helper(i, j-1);
            }
        return;
    }
    int maxSubStrLength(vector<char>& charList, string s) {
        // write code here
        S = s;
        CharList = charList;
        int n = s.size();
        res = 0;
        helper(0, n-1);
        return res;
    }
};