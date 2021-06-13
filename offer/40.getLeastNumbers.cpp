class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        // 空数组 和 一个元素的
        quickSortForK(arr, k, 0, arr.size()-1);
        vector<int> res;
        for(int i = 0; i < k; i++){
            res.push_back(arr[i]);
        }
        // res.assign(arr.begin(), arr.begin() + k); 这样要快些
        return res;
    }
    
    void quickSortForK(vector<int>& arr, int k, int l, int r){
        if(l >= r) return;
        int start = l;
        int end = r;
        int target = arr[l];
        while(l < r){
            while(l < r && arr[r] > target)
                r--;
            if(l < r)
                arr[l++] = arr[r];
        
            while(l < r && arr[l] < target)
                l++;
            if(l < r) 
                arr[r--] = arr[l];
        }
        arr[l] = target;
        if(l-start+1 == k)
            return;
        if(l-start+1 > k)
            quickSortForK(arr, k, start, l-1);
        else
            quickSortForK(arr, k-(l-start+1), l+1, end);
    }
};