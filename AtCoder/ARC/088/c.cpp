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
    LL x, y;cin >> x >> y;
    LL ans = 0;
    while(x <= y){
        ans++;
        x *= 2LL;
    }
    cout << ans << endl;
    return 0;
}
