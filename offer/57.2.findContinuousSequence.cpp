class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int i = 1, j = 2, sum = 3;
        vector<vector<int>> res;
        // 神奇的将口收在了 i == j 处
        while(i < j){
            if(sum == target){
                vector<int> temp;
                for(int k = i; k <= j; k++){
                    temp.push_back(k);
                }
                res.push_back(temp);
            }
            if(sum >= target){
                sum -= i;
                i++;
            }else{
                j++;
                sum += j;
            }
        }
        return res;
    }
};