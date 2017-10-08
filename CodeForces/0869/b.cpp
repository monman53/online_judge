// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (10LL)
#define EPS         (1e-10)
#define EQ(a, b)    (abs((a)-(b)) < EPS)

using P   = pair<int, int>;
using LL  = long long;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}


int main() {
    std::ios::sync_with_stdio(false);
    LL a, b;cin >> a >> b;
    LL ans = 1;
    for(;b>a;b--){
        ans *= b;
        ans %= 10LL;
        if(ans == 0LL) break;
    }
    cout << ans << endl;
    return 0;
}
