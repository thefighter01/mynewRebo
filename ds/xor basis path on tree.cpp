//#pragma GCC optimize ("O3")
//#pragma GCC optimize ("unroll-loops") // remember usage
#include<iostream>
#include <bits/stdc++.h>
#include <ext/numeric>
using namespace std;
using LL = __int128;
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define nd "\n"
#define all(x) (x).begin(), (x).end()
#define lol cout <<"i am here"<<nd;
#define py cout <<"YES"<<nd;
#define pp  cout <<"ppppppppppppppppp"<<nd;
#define pn cout <<"NO"<<nd;
#define popcount(x)  __builtin_popcount(x)
#define clz(n) __builtin_clz(n)//31 -x
const  double PI = acos(-1.0);
double EPS = 1e-9;
const ll N = 3e5+10, LOG = 20 , inf = 1e16, SQ= 200 , mod=1e9+7, mod2 = 998244353 , P1 = 31 , P2 = 29;
template<class container> void print(container v) { for (auto& it : v) cout << it << ' ' ;cout <<endl;}
//template <class Type1 , class Type2>
ll fp(ll a , ll p){ if(!p) return 1; ll v = fp(a , p/2); v*=v;return p & 1 ? v*a : v;  }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l , ll r) { return uniform_int_distribution<ll>(l, r)(rng); }
template <typename T> using ordered_set =  tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template< typename  T > using min_heap = priority_queue <T , vector <T >  , greater < T > >;
const ll B1 = 200117 , B2 = 200201;
//# define int long long // hay brother


ll mul (ll a, ll b , ll m){
    return ((a % m) *  (b % m)) % m;
}
ll add (ll a , ll b , ll m){
    return (a + b + m ) % m;
} // x ^ phi(m) is congruent to 1 mod m
// x ^ (phi -1) is congruent to  x^ -1 mod m
ll Fp (ll b , ll p , ll m){
    if (!p) return 1;
    ll v = Fp(b , p >> 1 , m);
    v = mul(v , v , m);
    if (p & 1) v = mul(v , b , m);
    return v;
}

ll modInv(ll n , ll m){
    return Fp(n , m-2 , m);
}


// E gym  , div1E tor , problem j //  div1 E , div1 D
int dx[] {0 , 0 , -1 , 1 ,-1 , 1 , 1 , -1};
int dy[] {-1 , 1 , 0 , 0 , -1 , 1 , -1 , 1};


const int M = 1e6+30;
ll INF = 1e8;


struct basis{ // take care of the size of the basis and the data type // can u use timer idea to solve subarray queries
    int sz;
    array < int , LOG+1 > d , T ;
    basis(){
        sz  = 0; for (int b = 0 ; b <= LOG; ++b) d[b] = 0;
    }
    bool bit(int mask, int i){
        return (mask >> i) & 1;
    }
    void push(int mask, int t){
        for (int b = LOG ; b >= 0 ; -- b){
            if (!bit(mask, b)) continue;
            if (!d[b]){
                d[b] = mask; ++sz;
                T[b] = t;
                return;
            }
            if (t > T[b]){
                swap(t , T[b]);
                swap(mask , d[b]);
            }
            mask ^= d[b];
        }
    }
    ll max_xor(){
        ll ans = 0;
        for (int b = LOG; b >= 0 ; --b){
            if (!bit(ans , b) && d[b]) ans^= d[b];
        }
        return ans;
    }
    bool check (int mask, int t){
        for (int b = LOG; b >= 0 ; --b){
            if (!bit(mask , b)) continue;
            if (!d[b] || t > T[b] ) return false;
            mask^= d[b];
        }
        assert(!mask);
        return true;
    }
    ll kth(int k){ // k th in sorted array , k <= 2 ^ sz
        ll mask = 0;
        ll tot = (1 << sz); assert(k <= tot);
        for (int b = LOG; b >= 0 ; --b){
            if (d[b]) {
                ll low = tot >> 1;
                if ((bit(mask, b) && k <= low) || (!bit(mask, b) && k > low)) mask ^= d[b];
                if (k > low) k -= low;
                tot = low;
            }
        }
        return mask;
    }
    bool empty() {return !sz;}
};

vector < int > value_of, dep;
vector < vector < int > > g , anc;
vector < pair < basis ,  array <int , 2 > > > ans;
vector < vector < int > > Q; basis old;
int n , qs;
void init(){
    g = vector < vector < int > > (n + 5);
    dep = value_of =vector < int > (n + 5);
    anc = vector < vector < int > > (n + 5 , vector < int > (LOG+ 1));
    Q = vector < vector < int > > (n + 5);  old = basis();
}


void dfs(int node , int p = 1){
    anc[node][0] = p; for (int L = 1; L < LOG; ++L) anc[node][L] = anc[anc[node][L-1]][L-1];
    for (auto &ch : g[node]){
        if (ch == p) continue;
        dep[ch] = 1 + dep[node];
        dfs(ch , node);
    }
}
int kth(int u , int k){
    for (int L = LOG-1 ; L >= 0 ; --L) if(k &(1 << L)) u = anc[u][L];
    return u;
}
int lca(int u, int v){
    if (dep[u] < dep[v]) swap(u, v);
    u = kth(u , dep[u] - dep[v]);
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0 ; --i){
        if (anc[u][i] ^ anc[v][i]) u = anc[u][i] , v = anc[v][i];
    }
    assert(u ^ v && anc[u][0] == anc[v][0]);
    return anc[u][0];
}

void merge(basis & u , basis & v){
    for (int i = 0 ; i <= LOG; ++i) if (v.d[i]) u.push(v.d[i],  v.T[i]);
}

void solve(int node , int p = 0){
    basis cur = old;  old.push(value_of[node] , dep[node]);
    for (auto &idx : Q[node]) merge(ans[idx].first , old);
    for (auto &ch : g[node]){
        if (ch == p) continue;
        solve(ch , node);
    }
    old = cur;
}

void main_(int tc) {
    cin >> n; init();
    for (int i = 1; i <=n; ++i) cin >> value_of[i];
    for (int u , v , i = 1; i < n; ++i){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> qs; dfs(1);
    ans = vector < pair < basis , array < int , 2 >  > > (qs + 1);
    for (int u , v, k , i = 1; i <= qs; ++i){
        cin >> u >> v >> k;
        int l = lca(u , v);
        Q[u].push_back(i);
        Q[v].push_back(i);
        ans[i].second = {k , dep[l]};
    }
    solve(1);
    for (int i = 1; i <= qs ; ++i) cout << (ans[i].first.check(ans[i].second[0], ans[i].second[1]) ? "YES" : "NO") << nd;







}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    //freopen("trains.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int tt = 1, tc = 0 ;//cin >> tt;
    while (tt--) main_(++tc);
#ifndef ONLINE_JUDGE
    cout << "Running Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s .\n";
#endif
    return 0;
}

