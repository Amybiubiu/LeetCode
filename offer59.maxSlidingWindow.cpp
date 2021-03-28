class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        if(n == 0){
            return res;
        }
        deque<int> dq;
        for(int i = 0; i < k; i++){
            while(!dq.empty() && dq.back() < nums[i]){
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        }
        res.push_back(dq.front());
        
        for(int i = 1; i + k -1 < n; i++){
            if(nums[i-1] == dq.front()){
                dq.pop_front();
            }
            while(!dq.empty() && dq.back() < nums[i+k-1]){
                dq.pop_back();
            }
            dq.push_back(nums[i+k-1]);
            res.push_back(dq.front());
        }
        return res;
    }
};