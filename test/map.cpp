 #include<iostream>
 #include<map>
 #include<string>
 using namespace std;

 int main()
 {
   map<char, string> myMap;
   myMap['a'] = "ahh!!";
   cout << myMap['a'] << endl << myMap['b'] << endl;
   return 0;
 }