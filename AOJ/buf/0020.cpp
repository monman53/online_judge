#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        cout << char(toupper(s[i]));
    }
    cout << '\n';
    return 0;
}
