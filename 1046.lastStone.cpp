class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //知道了priority_queue 这种东西不要太简单 朴素算法也就是排序+贪心吧？so boring
        priority_queue<int> q(stones.begin(),stones.end());
        while(q.size()>1){
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            if(a-b){
                q.push(a-b);
            }
        }
        return q.empty() ? 0 : q.top();
    }
};