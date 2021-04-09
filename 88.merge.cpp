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