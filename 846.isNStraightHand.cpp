class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int,int> s;
        for(int num : hand){
            ++s[num];
        }
        for(auto i = s.begin(); i != s.end(); i++){
            int num = i->first;
            int occ = i->second;
            if(occ>0){
                auto it = next(i);
                for(int i = 1; i < W; i++,it++){
                    if(it->second >= occ && (num+i)==it->first && it != s.end()){
                       it->second -=occ ;
                    }else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
  