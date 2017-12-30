#include <queue>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <string.h>
#include <math.h>
using namespace std;

double MAX_T = 9.95;
double UINT32_MAX_R = (double)1.0/UINT32_MAX;
//double ALPHA = 0.995;
double t     = 0.0;
double T     = 1.0;
double PROB  = 1.0;
int DIFF     = 9;

double sec = 0.0;

int full = 1;
int sparse = 1;

int n, ne, m, me;
int gh, geh;
char g[500][500], ge[3600][3600];
int gl[500][500];int gn[500];
int gel[3600][8];int gen[3600];
int u[20000], v[20000];
char w[501][501];

uint32_t xor128(void){
    static uint32_t x = 123456789;
    static uint32_t y = 362436069;
    static uint32_t z = 521288629;
    static uint32_t w = 88675123; 
    const uint32_t t = x ^ (x << 11);
    x = y; y = z; z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

struct State;
void state_init(struct State *s);
int state_score(const struct State *s);

struct State {
    int f[500];
    int fr[3601];
    int score;
};

void state_init(struct State *s) {
    int di[] = {0, -1, -1, -1, 0, 1, 1, 1};
    int dj[] = {1, 1, 0, -1, -1, -1, 0, 1};

    int kita[60][60];
    memset(kita, 0, sizeof(kita));
    priority_queue<pair<double, pair<int, int>>> pq;
    pq.push({0, {geh/2, geh/2}});
    int k = 0;
    while(k < n){
        auto c = pq.top();
        pq.pop();
        int i = c.second.first;
        int j = c.second.second;
        if(kita[i][j]) continue;
        kita[i][j] = 1;
        s->f[k] = i*geh + j;
        k++;
        for(int l=0;l<8;l++){
            int ni = i + di[l];
            int nj = j + dj[l];
            if(ni >= 0 && ni < geh && nj >= 0 && nj < geh){
                double di = ni - geh/2;
                double dj = nj - geh/2;
                pq.push({-(di*di+dj*dj), {ni, nj}});
            }
        }
    }
    for(int i=0;i<=ne;i++){
        s->fr[i] = n;
    }
    for(int i=0;i<n;i++){
        s->fr[s->f[i]] = i;
    }
    s->score = state_score(s);
}

inline int state_score(const struct State *s) {
    int ret = 0;
    for(int i=0;i<m;i++){
        int uu = s->f[u[i]];
        int vv = s->f[v[i]];
        if(ge[uu][vv]){
            ret += w[u[i]][v[i]];
        }
    }
    return ret;
}

inline int state_swap_s(const struct State *s, int i, int j) {
    int diff = 0;
    for(int k=0;k<8;k++){
        const int kri = s->fr[gel[s->f[i]][k]];
        const int krj = s->fr[gel[s->f[j]][k]];
        diff += (w[j][kri] - w[i][kri]) + (w[i][krj] - w[j][krj]);
    }
    if(ge[s->f[i]][s->f[j]]) diff += 2*w[i][j];
    return diff;
    //if(s->score != state_score(&s) printf("!!!!!\n");
}

inline void state_swap(struct State *s, int i, int j) {
    // swap f[i], f[j]
    int tmp = s->f[i];
    s->f[i] = s->f[j];
    s->f[j] = tmp;

    // swap fr[i], fr[j]
    tmp = s->fr[s->f[i]];
    s->fr[s->f[i]] = s->fr[s->f[j]];
    s->fr[s->f[j]] = tmp;
}

inline void state_print(const struct State *s) {
    char c[60][60];
    for(int i=0;i<geh;i++){
        for(int j=0;j<geh;j++){
            c[i][j] = '.';
        }
    }
    for(int k=0;k<n;k++){
        int i = s->f[k]/geh;
        int j = s->f[k]%geh;
        c[i][j] = '#';
    }
    for(int i=0;i<geh;i++){
        for(int j=0;j<geh;j++){
            printf("%c", c[i][j]);
        }
        printf("\n");
    }
}

int main() {
    clock_t start = clock();

    memset(g, 0, sizeof(g));
    memset(gn, 0, sizeof(gn));
    memset(ge, 0, sizeof(ge));
    memset(gen, 0, sizeof(gen));
    memset(w, 0, sizeof(w));

    //----------------
    // input
    //----------------
    // {{{
    
    // G
    scanf("%d %d", &n, &m);
    for(int i=0;i*i<n;i++){
        gh = i;
    }
    gh++;
    for(int i=0;i<m;i++){
        int uu, vv, ww;scanf("%d %d %d", &uu, &vv, &ww);uu--;vv--;
        u[i] = uu;v[i] = vv;
        g[uu][vv] = g[vv][uu] = 1;
        gl[uu][gn[uu]] = vv;gn[uu]++;
        gl[vv][gn[vv]] = uu;gn[vv]++;
        w[uu][vv] = w[vv][uu] = ww;
    }
    for(int i=0;i<n;i++){
        if(gn[i] != n-1){
            full = 0;
        }
        if(gn[i] > 8){
            sparse = 0;
        }
        w[i][n] = w[n][i] = 0;
        w[n][n] = 0;
    }

    // GE
    scanf("%d %d", &ne, &me);
    for(int i=0;i<me;i++){
        int a, b;scanf("%d %d", &a, &b);a--;b--;
        ge[a][b] = ge[b][a] = 1;
        gel[a][gen[a]] = b;gen[a]++;
        gel[b][gen[b]] = a;gen[b]++;
    }
    for(int i=0;i<ne;i++){
        while(gen[i] < 8){
            gel[i][gen[i]] = ne;
            gen[i]++;
        }
    }
    for(int i=0;i*i<=ne;i++) geh = i;
    // }}}

    //----------------
    // calc
    //----------------
    // {{{

    // params

    // init
    int count = 0;
    const int mask = (1 << 18) -1;
    clock_t end = clock();
    struct State state;state_init(&state);
    struct State best = state;
    int i, j;
    int diff;

    // routine
    while(1){
        if(!(count & mask)){
            end = clock();
            sec = (double)(end - start)/CLOCKS_PER_SEC;
            t   = sec/MAX_T;
            //T   = pow(ALPHA, sec/MAX_T);
            if(full){
                //PROB = 0.3-0.0*t; 
                PROB = 0.35-0.10*t; 
                //PROB = 0.5-0.4*t; 
                DIFF = 8;
            }else if(sparse){
                ///PROB = 0.4-0.4*(sec/MAX_T);
                //PROB= 0.4;
                PROB = 1.0-1.0*t;
                DIFF = 6;
            }else{
                //PROB = 0.6-0.4*(sec/MAX_T); 
                PROB = 0.9-0.9*t; 
                //PROB = 1.0/(1.0+exp(-5*(0.5-sec/MAX_T))); // logistic
                //PROB = -t*t+1.0;
                DIFF = 9;
            }
            if(sec > MAX_T) break;
            //state_print(&best);
            //cout << best.score_() << " " << best.score << endl;
            //printf("%d\n", best.score);
        }
        count++;

        i = xor128()%n;
        j = xor128()%n;
        diff = state_swap_s(&state, i, j);


        if(diff >= 0){
            state.score += diff;
            state_swap(&state, i, j);
            if(state.score > best.score){
                best = state;
            }
        }else if(diff > -DIFF){
            if(xor128()*UINT32_MAX_R <= PROB){
                state.score += diff;
                state_swap(&state, i, j);
            }
        }
    }
    // }}}

    while(1){
        int flag = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                const int diff = state_swap_s(&best, i, j);
                if(diff > 0){
                    //cout << "!!!!!!" << b-a << endl;
                    flag = 1;
                    best.score += flag;
                    state_swap(&best, i, j);
                }
            }
        }
        end = clock();
        sec = (double)(end - start)/CLOCKS_PER_SEC;
        if(sec > MAX_T+0.035) break;
        if(!flag) break;
    }

    //----------------
    // output
    //----------------
    for(int i=0;i<n;i++){
        printf("%d %d\n", i+1, best.f[i]+1);
    }

    return 0;
}