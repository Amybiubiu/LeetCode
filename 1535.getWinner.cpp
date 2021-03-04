class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        auto p = nullptr;
        int win_count = 0;
        int winner = 0;
        if( k >= arr.size()){
            k = arr.size() - 1;
        }
        while(win_count < k){
            auto loser_p = arr.begin();
            auto winner_p = next(loser_p, 1);
            if(arr[0] > arr[1]){
                winner_p = arr.begin();
                loser_p = next(winner_p, 1);
            }
            // after each push, vector will be relocated
            // after push back the loser_p have changed, so erase the incorrect value
            // arr.push_back(*loser_p);
            // arr.erase(loser_p);
            int temp = *loser_p;
            arr.erase(loser_p);
            arr.push_back(temp);
            // after erase the *winner_p have changed, so lead to error
            if(*winner_p == winner){
                win_count++;
            }else{
                winner = *winner_p;
                win_count = 1;
            }     
        }
        return winner;
    }
};
// 不要改变 vector 后又使用指针指向的值

// 小的数字在比较中是不重要的
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int max = arr[0];
        int count = 0;
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] > max){
                max = arr[i];
                count = 1;
            }else{
                count++;
            }
            if(count == k)
                break;
        }
        return max;
    }
};