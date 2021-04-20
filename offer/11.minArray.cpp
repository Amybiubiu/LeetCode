// class Solution {
// public:
//     int minArray(vector<int>& numbers) {
//         int n = numbers.size();
//         if(!n){
//             return -1;
//         }
//         int l = 0;
//         int r = n-1;
//         int mid = 0;
//         while(numbers[l] >= numbers[r]){
//             if(r - l == 1){
//                 mid = r;
//                 break;
//             }
//             mid = (l+r)/2;
            
//             if(numbers[mid] >= numbers[l]){
//                 l = mid;
//             }else if(numbers[mid] <= numbers[r]){
//                 r = mid;
//             }
//         }
//         return numbers[mid];
//     }
// };
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            int m = (i + j) / 2;
            if (numbers[m] > numbers[j]) i = m + 1;
            else if (numbers[m] < numbers[j]) j = m;
            else {
                int x = i;
                for(int k = i + 1; k < j; k++) {
                    if(numbers[k] < numbers[x]) x = k;
                }
                return numbers[x];
            }
        }
        return numbers[i];
    }
};
