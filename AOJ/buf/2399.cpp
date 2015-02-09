#include <iostream>
#include <set>
using namespace std;

int main(){
    while(1){
        int n,k;
        cin >> n;
        if(n == 0) break;

        set<int> known[101];
        for(int i=1;i<=n;i++){
            int m;
            cin >> m;
            for(int j=0;j<m;j++){
                int p;
                cin >> p;
                known[i].insert(p);
            }
        }
        cin >> k;
        int l[k];
        for(int i=0;i<k;i++){
            cin >> l[i];
        }
        int count=0;
        int hannin;
        for(int i=1;i<=n;i++){
            bool check=true;
            for(int j=0;j<k;j++){
                if(known[i].count(l[j]) == 0){
                    check = false;
                    break;
                }
            }
            if(check){
                count++;
                hannin = i;
            }
        }
        if(count == 1){
            cout << hannin << '\n';
        }else{
            cout << -1 << '\n';
        }               
    }
    return 0;
}
