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
#define CILING(a, b)    (((a)+(b)-1LL)/(b))

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
    int n, k;cin >> n >> k;
    vector<int> cmax(ALPHABET, -1);
    vector<int> cmin(ALPHABET, INT_MAX);
    string s;cin >> s;
    for(int i=0;i<n;i++){
        int id = s[i]-'A';
        cmax[id] = max(cmax[id], i);
        cmin[id] = min(cmin[id], i);
    }
    vector<int> imos(n+1, 0);
    for(int i=0;i<ALPHABET;i++){
        if(cmax[i] != -1){
            imos[cmin[i]]++;
            imos[cmax[i]+1]--;
        }
    }
    int now = 0;
    bool flag = false;
    for(int i=0;i<n;i++){
        now += imos[i];
        if(now > k) flag = true;
    }
    cout << (flag ? "YES" : "NO") << endl;
    return 0;
}
