class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // id, time
        unordered_map<int, vector<int>> managepeople;
        
        // 妙啊
        for (int i = 0; i < n; i++) {
            managepeople[manager[i]].push_back(i);
        }
        queue<pair<int, int>> qu;
        qu.push({headID, informTime[headID]});

        int ans = 0;
        while (!qu.empty()) {
            int sz = qu.size();

            for (int i = 0; i < sz; i++) {
                auto cur = qu.front();
                qu.pop();
                int id = cur.first;
                int step = cur.second;

                ans = max(ans, step);

                for (int j = 0; j < managepeople[id].size(); j++) {
                    int child_id = managepeople[id][j];
                    if(managepeople[child_id].size()){
                        qu.push({managepeople[id][j], step + informTime[managepeople[id][j]]});
                    }
                }
            }
        }
        return ans;
    }
};

// 11
// 4
// [5,9,6,10,-1,8,9,1,9,3,4]
// [0,213,0,253,686,170,975,0,261,309,337]
// 这个case过不了 这不是逐层求最大。975 的大于 261+170 所以 不需要再加上170。
// 这是求出所有从0到末梢的最长路径的一道题。所以上面才是正确的解法
// 如果是这样的话，深搜也合适。
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> managePeople(n);
        // vector<vector<int>> managePeople(n); 用vector不行是因为出现了一个-1的下标。
        for(int i = 0; i < n; i++){
            managePeople[manager[i]].push_back(i);
        }

        queue<int> q;
        q.push(headID);
        int res = 0;
        
        while(!q.empty()){
            int size = q.size();
            int _max = 0;
            for(int i = 0; i < size; i++){
                int id = q.front();
                q.pop();
                
                _max = max(_max, informTime[id]);
                
                for(int j = 0; j < managePeople[id].size(); j++){
                    q.push(managePeople[id][j]);
                }
            }
            res += _max;
        }

        return res;
    }
};