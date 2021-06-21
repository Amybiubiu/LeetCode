class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        string res ="";
        if(!nums.size()) return res;
        for(auto & num : nums)
            strs.push_back(to_string(num));
        quickSort(strs, 0, strs.size()-1);
        
        for(auto& str : strs)
            res.append(str);
        return res;   
    }
    void quickSort(vector<string>& strs, int l, int r){
        if(l >= r) return;
        int i = l, j = r;
        while(i < j){
            // 此处要取等号 不然会无限while
            while(i < j && strs[j] + strs[l] >= strs[l] + strs[j])
                j--;
            while(i < j && strs[i] + strs[l] <= strs[l] + strs[i])
                i++;
            swap(strs[i], strs[j]);
        }
        swap(strs[i], strs[l]);
        
        quickSort(strs, l, i-1);
        quickSort(strs, i+1, r);
    }
};