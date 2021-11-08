class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // j 指向 n2 ；k 指向 n1
        int i = m+n-1, j = n-1, k = m-1;
        while( i>= 0 && k >= 0 && j >= 0){
            if(nums2[j] > nums1[k]){
                // cout<<"yes"<<endl;
                nums1[i--] = nums2[j--];
            }else{
                nums1[i--] = nums1[k--];
            }
            // if(i >= 0){
            //     cout<<nums1[i]<<endl;
            // }
        }
        while(j >= 0){
            nums1[i--] = nums2[j--];
        }
        // while(k >= 0){
        //     nums1[i--] = nums2[k--];
        // }
    }
};

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> copyNums1(nums1.begin(), nums1.begin() + m);
        // for(int i = 0; i < m; i++){
        //     copyNums1[i] = nums1[i];
        // }
        if(n == 0) return;
        int i = 0, j = 0, k = 0;
        while(i < m && j < n){
            while(i < m && copyNums1[i] < nums2[j]){
                nums1[k++] = copyNums1[i];
                i++;
            }
            if(i < m){
                nums1[k++] = nums2[j++];
            }
        }
        while(i < m){
            nums1[k++] = copyNums1[i++];
        }
        while(j < n){
            nums1[k++] = nums2[j++];
        }
    }
};

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = 0, p2 = 0;
        int sorted[m + n];
        int cur;
        while (p1 < m || p2 < n) {
            if (p1 == m) {
                cur = nums2[p2++];
            } else if (p2 == n) {
                cur = nums1[p1++];
            } else if (nums1[p1] < nums2[p2]) {
                cur = nums1[p1++];
            } else {
                cur = nums2[p2++];
            }
            sorted[p1 + p2 - 1] = cur;
        }
        for (int i = 0; i != m + n; ++i) {
            nums1[i] = sorted[i];
        }
    }
};