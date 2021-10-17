class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int N = prerequisites.size() + numCourses;
        // int N = 10010;
        if(!N) return {};

        int idx = 0, e[N], h[N], ne[N];
        memset(e, 0, sizeof e);
        memset(h, -1, sizeof h);
        memset(ne, 0, sizeof ne);

        int q[N], d[numCourses];
        memset(q, 0, sizeof q);
        memset(d, 0, sizeof d);

        // 初始化数据
        for(int i = 0; i < prerequisites.size(); i++){
            e[idx] = prerequisites[i][0];
            ne[idx] = h[prerequisites[i][1]];
            h[prerequisites[i][1]] = idx++;
            d[prerequisites[i][0]]++;
        }
    
        // 拓扑排序
        int hh = 0, tt = -1;
        for(int i = 0; i < numCourses; i++){
            if(d[i] == 0){
                q[++tt] = i;
            }
        }

        while(hh <= tt){
            int u = q[hh++];
            for(int i = h[u]; i != -1; i = ne[i]){
                int j = e[i];
                if(--d[j] == 0){
                    q[++tt] = j;
                }
            }
        }
        // 输出结果
        if(tt == numCourses-1){
            return vector<int>(q, q+tt+1);
        }else{
            return {};
        }
    }
};