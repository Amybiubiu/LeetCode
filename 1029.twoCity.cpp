class Solution {
    public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // Sort by a gain which company has 
        // by sending a person to city A and not to city B
        sort(begin(costs), end(costs),
                [](const vector<int> &o1, const vector<int> &o2) {
            return (o1[0] - o1[1] < o2[0] - o2[1]);
        });

        int total = 0;
        int n = costs.size() / 2;
        // To optimize the company expenses,
        // send the first n persons to the city A
        // and the others to the city B
        for (int i = 0; i < n; ++i) total += costs[i][0] + costs[i + n][1];
        return total;
    }
};
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        sort(costs.begin(),costs.end(),
             [](vector<int> a,vector<int> b){return abs(a[0]-a[1]) > abs(b[0]-b[1]);});
        int l = 0;
        int r = 0;
        int res = 0;
        for(int i = 0; i < n ; i++){
            if(costs[i][0] < costs[i][1]){
                if( l < n/2){
                   res += costs[i][0];
                   l++; 
                }else{
                   res += costs[i][1];
                   r++; 
                }
            }else{
                if( r < n/2){
                    res += costs[i][1];
                    r++;
                }else{
                   res += costs[i][0];
                   l++;  
                }
            }
        }
        return res;
    }
};
//看看人家 再看看你的 你写的是什么狗屎代码？？？