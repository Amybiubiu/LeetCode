#include <iostream>
#include <vector>
#include <map>
using namespace std;
// class Solution {
// public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        map<int,int> m;
        for(int num : A){
            ++m[num];
        }
        for(int num : B){
            ++m[num];
        }
        int max_count = 0;
        int target;
        for(auto it = m.begin(); it != m.end(); it++){
            if(it->second >= max_count){
                max_count = it->second;
                target = it->first;
            }
        }
        int a=0;
        int b=0;
        for(int i = 0; i < A.size(); i++){
            if(A[i]!=target && B[i]!=target){
                return -1;
            }
            a=(A[i]==target)?++a:a;
            b=(B[i]==target)?++b:b;
        }
        return min(A.size()-a,B.size()-b);
    }
// };
int main(){
    int n[] = {1, 2, 1, 1, 1,2,2,2};
    int m[] = {2, 1, 2, 2, 2,2,2,2};
    vector<int> a(n, n+8);
    vector<int> b(m, m+8);
    cout<<minDominoRotations(a,b)<<endl;
    return 0;
}