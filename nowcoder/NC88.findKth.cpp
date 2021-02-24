class Solution {
public:
    int findKth(vector<int> a, int n, int K) {
        // write code here
        return quickSort(a, 0, n-1, K);
    }
    int quickSort(vector<int> a, int left, int right, int k){
        int i = left;
        int j = right;
        int mark = a[left];
        while(i < j){
            while(i < j && a[j] > mark)
                j--;
            if(i < j)
                a[i++] = a[j];
            while(i < j && a[i] < mark)
                i++;
            if(i < j)
                a[j--] = a[i];
        }
        a[i] = mark;
        int big_num = right - i;
        if(k - big_num == 1)
            return mark;
        if(k - big_num > 1)
            return quickSort(a, left, i - 1, k - big_num -1);
        else
            return quickSort(a, i+1, right, k);
    }
};