// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)

using LL  = long long;
// }}}

int main() {
    std::ios::sync_with_stdio(false);
    int a, b, c, d;cin >> a >> b >> c >> d;
    if(a+b > c+d){
        cout << "Left" << endl;
    }else if(a+b < c+d){
        cout << "Right" << endl;
    }else{
        cout << "Balanced" << endl;
    }
    return 0;
}
