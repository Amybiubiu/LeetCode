class Solution {
public:
    string replaceSpace(string s) {
        int n = s.size();
        int spaceNum = 0;
        if(!n){
            return s;
        }
        for(auto& i : s){
            if(i == ' '){
                spaceNum++;
            }
        }
        s.resize(n+spaceNum*2);
        for(int i = n-1, j = s.size()-1; i<j; i--,j--){
            // cout<<s[i];
            if(s[i] == ' '){
                s[j] = '0';
                s[j-1] = '2';
                s[j-2] = '%';
                j = j - 2;
            }else{
                s[j] = s[i];
            }
        }
        return s;
    }
};