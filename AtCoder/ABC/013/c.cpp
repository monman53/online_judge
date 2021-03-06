// header {{{
// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define ALPHABET    (26)
#define INF         INT_MAX
#define MOD         (1000000007LL)
#define EPS         (1e-10)
#define EQ(a, b)        (abs((a)-(b)) < EPS)
#define CILING(a, b)    (((a)+(b)-1)/(b))

template<class T>
using PIT = pair<int, T>;
template<class T>
using PTI = pair<T, int>;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using LL  = long long;
using ULL = unsigned long long;
// }}}


int main() {
    LL n, h, a, b, c, d, e;
    cin >> n >> h >> a >> b >> c >> d >> e;

    LL ans = LLONG_MAX;

    for(LL i=0;i<=n;i++){
        LL j = ((n-i)*e-h-b*i)/(d+e) + 1L;
        if((n-i)*e-h-b*i <= 0) j = 0;
        if(j+i <= n){
            ans = min(ans, a*i+c*j);
        }
    }

    printf("%lld\n", ans);

    return 0;
}
