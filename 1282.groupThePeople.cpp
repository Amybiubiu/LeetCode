class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map <int,vector<int>> groups;
        for(int i = 0; i < groupSizes.size(); i++){
            groups[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> res;
        for(auto group = groups.begin(); group != groups.end(); group++){
            int size = group->first;
            vector<int> data = group->second;
            for(auto iter = data.begin(); iter != data.end(); iter = next(iter,size)){
                vector<int> dummy(iter,next(iter,size));//倒是有些奇怪？
                    res.push_back(dummy);
            }
        }
        return res;
    }
};