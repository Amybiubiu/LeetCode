class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long target = 0;
        for(auto i : nums)
            target -= i;
        target += goal;
        int count = 0;
        // while(target != 0){
        //     int temp = 0;
        //     if(abs(target) >= limit){
        //         temp = target < 0 ? limit : 0 - limit;
        //     }else{
        //         temp = 0 - target;
        //     }
        //     target += temp; 
        //     count++;
        // }
        if(target < 0) target = 0 - target;
        count += target%limit == 0 ? target/limit : target/limit + 1;
        return count;
    }
};