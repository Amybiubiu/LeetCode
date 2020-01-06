#include <iostream>
#include <vector>
using namespace std;

void solve(vector<vector<int> >& res,vector<int> nums,vector<int> path,int s){
    for(int i=s;i<nums.size();i++){
        if(i>s && nums[i] == nums[i-1])
            continue;
        
        path.push_back(nums[i]);
        res.push_back(path);

        solve(res,nums,path,s+1);
        path.pop_back();
    }
}
vector<vector<int> > subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int> > res;
    vector<int> path;
    res.push_back(path);
    
    solve(res,nums,path,0);
    return res;
}


int main(){
    vector<int> test;
    test[0]=1;
    test[1]=2;
    test[2]=2;
    vector<vector<int> > res = subsetsWithDup(test);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++)
            std::cout<<res[i][j]<<" ";
        std::cout<<endl;
    }
    return 0;
}