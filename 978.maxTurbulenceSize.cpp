class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        
        int res = 1;
        int anchor = 0;

        for(int i = 1; i < n; i++){
            int left_dis = compare(arr[i-1], arr[i]);
            if( i == n-1 || left_dis * compare(arr[i], arr[i+1]) != -1 ){
               if(left_dis){
                   res = max(res, i - anchor + 1);
               }
                anchor = i;
            }
                
        }
        return res;
    }
    int compare(int a, int b){
        if(a < b){
            return 1;
        }else if( a == b){
            return 0;
        }else{
            return -1;
        }
    }
};

