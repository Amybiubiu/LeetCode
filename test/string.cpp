#include <iostream>
using namespace std;

int main(){
    std::string S("Hey");
    // S.push_back('\0');
    // S.append("Jude");

    // for(int i = 0; S[i] != '\0'; ++i)
    for(int i = 0; i < S.size(); ++i)
        std::cout << S[i];
    cout<<"a"<<endl;
    return 0;
}
