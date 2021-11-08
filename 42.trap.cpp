class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 1) return 0;
        vector<int> left_max(n);
        vector<int> right_max(n);
        left_max[0] = height[0];
        for(int i = 1; i < n; i++){
            left_max[i] = max(height[i], left_max[i-1]);
        }
        right_max[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--){
            right_max[i] = max(height[i], right_max[i+1]);
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            // cout<<left_max[i]<<" "<<right_max[i]<<endl;
            res += min(left_max[i], right_max[i]) - height[i];
            // cout<<res<<endl;
        }
        return res;
    }
};