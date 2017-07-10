// header {{{
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <complex>
#include <utility>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <list>
#include <set>
#include <stack>
#include <tuple>
#include <cstdio>
#include <cmath>
using namespace std;

#define ALPHABET    (26)
#define EPS         (1e-10)
#define INF         (1000000005LL)
#define MOD         (1000000007LL)
#define EQ(a, b)    (abs((a)-(b)) < EPS)
// ciling(x/y) = (x+y-1)/y

typedef long long ll;
typedef unsigned long long ull;
// }}}

int main() {
    int n;cin >> n;
    map<int, int> m;
    for(int i=0;i<n;i++){
        int a;cin >> a;
        m[a]++;
    }
    int count = 0;
    for(auto kv : m){
        if(kv.second%2 == 0){
            count++;
        }
    }
    cout << m.size()-(count%2) << endl;
    return 0;
}
