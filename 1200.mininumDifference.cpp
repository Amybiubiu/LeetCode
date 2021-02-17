class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        // sort 
        sort(arr.begin(),arr.end());
        int minDiff=INT_MAX;
        vector<vector<int>>res;
        for(int i=1;i<arr.size();++i)
        {
            if(arr[i]-arr[i-1]<minDiff)
            {
                // clear
                res.clear();
                // push_back
                res.push_back({arr[i-1],arr[i]});
                minDiff=arr[i]-arr[i-1];
            }
            else if(arr[i]-arr[i-1]==minDiff)
                 res.push_back({arr[i-1],arr[i]});
        }
        return res;
    }
};