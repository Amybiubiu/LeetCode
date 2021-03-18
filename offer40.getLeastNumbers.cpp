class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        // 超时的往小冒泡
        vector<int> res;
        if(arr.size() == 0)
            return res;
        for(int i = 0; i < k; i++){
            int min = arr[i];
            for(int j = i+1; j < arr.size(); j++){
                if(arr[j] < min){
                    min = arr[j];
                    arr[j] = arr[i];
                    arr[i] = min;
                }
            }
            res.push_back(min);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        quickSort(arr, 0, arr.size()-1);
        vector<int> res;
        res.assign(arr.begin(), arr.begin() + k);
        return res;
    }
    
    void quickSort(vector<int>& arr, int i, int j){
        if(i >= j) return;
        int left = i;
        int right = j;
        int mark = arr[left];
        while(left < right){
            while(arr[right] > mark && right > left){
                right--;
            }
            if(left < right){
                arr[left++] = arr[right]; 
            // 
            }
            while(arr[left] < mark && left < right){
                left++;
            }
            if(left < right){
                arr[right--] = arr[left];
            } 
        }
        arr[left] = mark;
        quickSort(arr, i, left - 1);
        quickSort(arr, left+1, j);
    }
};