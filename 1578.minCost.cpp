class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int res = 0;
        int i = 0;
        while(i < s.size() - 1){
            if( s[i] == s[i+1] ){
                if(cost[i] < cost[i+1]){
                    res += cost[i];
                }else{
                    res += cost[i+1];
                    cost[i+1] = cost[i];
                }
            }
            i++;
        }
        return res;
    }
};