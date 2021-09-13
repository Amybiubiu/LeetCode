#include <iostream>
using namespace std;

int main(){
    // cin
    int size = 0;
    cin>>size;
    vector<int> arr;
    for(int i = 0; i < size; i++){
        cin>>arr[i];
    }
    // resolution
    return 0;
}
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(!nums.size()) return 0;
        int count = 0;
        
        int i = 0, j = nums.size() - 1;
        while(i < j){
            int mid = (i+j+1)>>1;
            if(nums[mid] <= target){
               i = mid;
            }else{
               j = mid-1;
            }
        }
        if(nums[i] == target)
            count = 1;
        while(i > 0 && nums[--i] == target ){
            count++;
        }
        return count;
    }
};