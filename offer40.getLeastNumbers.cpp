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
            if(i < j){
                arr[left++] = arr[right]; 
            // 
            }
            while(arr[left] < mark && left < right){
                left++;
            }
            if(i < j){
                arr[right--] = arr[left];
            } 
        }
        arr[left] = mark;
        quickSort(arr, i, left - 1);
        quickSort(arr, left+1, j);
    }
};
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        quickSort(arr, 0, arr.size() - 1);
        vector<int> res;
        res.assign(arr.begin(), arr.begin() + k);
        return res;
    }
private:
    void quickSort(vector<int>& arr, int l, int r) {
        // 子数组长度为 1 时终止递归
        if (l >= r) return;
        // 哨兵划分操作（以 arr[l] 作为基准数）
        int i = l, j = r;
        while (i < j) {
            while (i < j && arr[j] >= arr[l]) j--;
            while (i < j && arr[i] <= arr[l]) i++;
            swap(arr[i], arr[j]);
        }
        swap(arr[i], arr[l]);
        // 递归左（右）子数组执行哨兵划分
        quickSort(arr, l, i - 1);
        quickSort(arr, i + 1, r);
    }
};


