class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 1)
            return n;
        sort(points.begin(), points.end(), [](vector<int> a, vector<int> b) -> bool {return a[0] < b[0];});
        int res = 1;
        int region_r = points[0][1];
        // int region_l = points[0][0];
        for(int i = 1; i < n; i++){
            if(points[i][0] > region_r){
                res++;
                // region_l = points[i][0];
                region_r = points[i][1];
            }else{
                // region_l = points[i][0];
                region_r = min(points[i][1], region_r);
            }
        }
        return res;
    }
};