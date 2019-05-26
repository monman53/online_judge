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

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int m, k;cin >> m >> k;
    //if(m == 0 && k == 0){
        //cout << 0 << " " << 0 << endl;
        //return 0;
    //}
    if(k >= (1<<m) || (m == 1 && k > 0)){
        cout << -1 << endl;
        return 0;
    }

    vector<int> ans;
    if(k == 0){
        inc(i, 0, (1<<m)){
            ans.pb(i);
            ans.pb(i);
        }
    }else{
        ans.pb(0);
        ans.pb(k);
        ans.pb(0);
        inc(i, 1, (1<<m)){
            if(i == k) continue;
            ans.pb(i);
        }
        ans.pb(k);
        dec(i, 1, (1<<m)){
            if(i == k) continue;
            ans.pb(i);
        }
    }

    int n = ans.size();
    inc(i, 0, n){
        cout << ans[i];
        if(i != n-1){
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}
