#include <iostream>
#include <climits>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
using namespace std;

// Union-Find
// verified AOJ DSL_1_A
struct UF {
    vector<int> p;  // parent
    vector<int> r;  // rank

    UF(int n) {
        p.resize(n);
        r.resize(n);
        for(int i=0;i<n;i++){
            p[i] = i;
            r[i] = 1;
        }
    }

    int find(int x) {
        if(x == p[x]){
            return x;
        }else{
            return p[x] = find(p[x]);
        }
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(r[x] < r[y]){
            p[x] = y;
        }else{
            p[y] = x;
            if(r[x] == r[y]){
                r[x]++;
            }
        }
    }
};


int main(){
    int n,q;
    cin >> n >> q;
    
    UF uf(n);

    for(int i=0;i<q;i++){
        int com, x, y;
        cin >> com >> x >> y;
        if(com == 0){
            uf.unite(x, y);
        }else{
            if(uf.find(x) == uf.find(y)){
                cout << 1 << endl;
            }else{
                cout << 0 << endl;
            }
        }
    }
    return 0;
}
