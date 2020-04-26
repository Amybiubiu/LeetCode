class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        //个子矮的人相对于个子高的人是不被看见的 哈哈哈哈哈 有被笑到
        // 不清楚STL特性 真的很难搞 又萌生了想买 c++ primer 的心 划掉 萌生了看电子版 c++ primer的心
        sort(people.begin(),people.end(),
            [](vector<int> a,vector<int> b){return a[0] == b[0]?a[1]<b[1] : a[0] > b[0];});
        int n = people.size();
        list<vector<int>> tmp;
        for(int i = 0; i < n ; i++){
            auto pos = tmp.begin();
            advance(pos,people[i][1]);
            tmp.insert(pos,people[i]);  //insert 牛啊
        }
         return vector<vector<int>>(tmp.begin(), tmp.end());
    }
};