class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.size() == 0) return true;
        return helper(postorder, 0, postorder.size()-1);
    }
    bool helper(vector<int>&postorder, int l, int r){
        int i = l;
        while(i < r && postorder[i] < postorder[r]){
            i++;
        }
        int j = i;
        for( ; j < r; j++){
            if(postorder[j] < postorder[r]){
                return false;
            }
        }
        bool left = true;
        if(i > l){
            left = helper(postorder, l, i-1);
        }
        bool right = true;
        if(i < r){
            right = helper(postorder, i, r-1);
        }
        return left&&right;
    }
};