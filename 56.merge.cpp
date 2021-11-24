class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){return a[0] < b[0];});
        vector<vector<int>> res;
        int begin = intervals[0][0], end = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            // cout<<intervals[i][0]<<intervals[i][1]<<endl;
            if(intervals[i][0] <= end){
                end = max(end, intervals[i][1]);
            }else{
                res.push_back({begin, end});
                begin = intervals[i][0];
                end = intervals[i][1];
            }
        }
        res.push_back({begin, end});
        return res;
    }
};