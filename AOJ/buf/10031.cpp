#include <iostream>
#include <set>
using namespace std;

int main(){
    int n,q;
    set<int> data;
    cin >> n;
    for(int i=0;i<n;i++){
        int m;
        cin >> m;
        data.insert(m);
    }

    cin >> q;
    int count = 0;
    for(int i=0;i<q;i++){
        int m;
        cin >> m;
//        cout << m;
        if(data.find(m) != data.end()){
            count++;
//            cout << "exsist";
        }
//        cout << '\n';
    }

    cout << count << '\n';
    return 0;
}
