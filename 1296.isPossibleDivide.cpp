class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        //special
        int n = nums.size();
        if(!k || n%k) return false;
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int s;
        for(int i = 0; i < n; i++){
            bool flag = false;
            for(int j = 0; j < res.size(); j++){
                s = res[j].size();
                if(s < k && (res[j][s-1]+1)== nums[i]){
                    res[j].push_back(nums[i]);
                    flag = true;
                    break;
                }
            }
            if(!flag){
                vector<int> item;
                item.push_back(nums[i]);
                res.push_back(item);
            }
        }
        for(int i = 0; i < res.size(); i++){
            if(res[i].size() != k)
                return false;
        }
        return true;
        //超时了 5⃣️ 36/39
    }
};
//官方题解 缩小了规模
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> s;
        for (int num: nums) {
            ++s[num];
        }
        for (auto iter = s.begin(); iter != s.end(); ++iter) {
            int num = iter->first;
            int occ = iter->second;
            if (occ > 0) {
                auto it = next(iter);
                for (auto i = 1; i < k; ++i, ++it) {
                    if (it != s.end() && it->first == num + i && it->second >= occ) {
                        it->second -= occ;
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};