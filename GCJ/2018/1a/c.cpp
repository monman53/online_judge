// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define LLINF       LLONG_MAX/3
#define MOD         (1000000007LL)
#define MODA(a, b)  a=((a)+(b))%MOD
#define MODP(a, b)  a=((a)*(b))%MOD
#define inc(i, l, r)   for(int i=(l);i<(r);i++)
#define dec(i, l, r)   for(int i=(r)-1;i>=(l);i--)
#define pb          push_back
#define se          second
#define fi          first
#define mset(a, b)  memset(a, b, sizeof(a))

using LL  = long long;
using G   = vector<vector<int>>;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

double solve() {
    int n;cin >> n;
    double p;cin >> p;
    double w, h;
    inc(i, 0, n){
        cin >> w >> h;
    }
    if(w < h) swap(w, h);
    double d = p - 2*(h+w)*n;
    int m = 0;
    inc(i, 0, n){
        if(d + 10e-7 > 2*h){
            d -= 2*h;
            m++;
        }else{
            break;
        }
    }
    inc(i, 0, m){
        double a = sqrt(h*h+w*w);
        if(d + 10e-7 > 2*a-2*h){
            d -= 2*a-2*h;
        }else{
            d = 0;
            break;
        }
    }
    return p-d;
}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int t;cin >> t;
    inc(i, 0, t){
        double ans = solve();
        printf("Case #%d: %.9lf\n", i+1, ans);
    }
    return 0;
}
