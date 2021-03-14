class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges;
        edges.resize(numCourses);
        vector<int> indeg(numCourses, 0);
        vector<int> res;
        
        for(auto i : prerequisites){
            edges[i[1]].push_back(i[0]);
            indeg[i[0]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indeg[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            res.push_back(temp);
            
            for(auto i : edges[temp]){
                indeg[i]--;
                if(indeg[i] == 0)
                    q.push(i);
            }
        }
        if(res.size() < numCourses)
            return {};
        return res;
    }
};

