# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<int> climbStairs(int n) {
        
        vector<int> a(n+1);
        a[0]=1;
        a[1]=1;
        int res;
        for(int i = 2;i<=n;i++){
            a[i]=a[i-1]+a[i-2];
            cout<<a[i]<<endl;
        }
        res = a[n];
        
        return a;
    }
};

int main(){
    Solution s;
    vector<int> res = s.climbStairs(3);

    return 0;
}