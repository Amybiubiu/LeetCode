class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        if(n == 0){
            return 0;
        }
        for(int i = 1; i < n; i++){
            int temp = prices[i]-prices[i-1];
            if(temp > 0)
                profit += temp;
        }
        return profit;
    }
};