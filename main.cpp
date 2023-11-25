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
const ll N = 2e5+10, LOG = 20 , inf = 1e16, SQ= 200 , mod=1e9+7, mod2 = 998244353 , P1 = 31 , P2 = 29;
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


const int M = 2e7+5;

ll INF = 1e12;
int n , dfn , qs ;
vector < vector < int >> g;
vector < vector< array< int , 3 > > > q;
vector < int > p , st ,sz , inv , ans;
multiset < int > ds;
void init(){
    inv =  p = sz = st = vector < int > (n+5);
    q = vector < vector< array < int , 3 > > > (n+5);
    g = vector < vector < int > > (n+5);
    ans =vector < int > (qs+5);
    dfn = 0;
    assert (ds.empty());
}
void dfs (int node ,int pa){
    sz[node] = 1; inv[st[node] = ++ dfn] = node;
    for (auto &ch: g[node]){
        if (ch == pa) continue;
        dfs(ch , node);
        sz[node]+=sz[ch];
    }
}
void solve (int node, int pa , bool keep = 0){
    int heavy = 0;
    for (auto ch : g[node]) if (ch != pa && sz[ch] > sz [heavy]) heavy = ch;
    for (auto ch : g[node]) if (ch ^pa && ch ^ heavy) solve(ch , node);
    if (heavy) solve(heavy , node, 1);
    // add node
    ds.emplace (p[node]);
    // add chs
    for (auto ch : g[node]){
        if (ch == pa || ch == heavy) continue;
        for (int L = st[ch]; L < st [ch] + sz[ch] ; ++L)
            ds.emplace(p[inv[L]]);
    }

    // answer queries
    for (auto [L , R , idx] : q[node]){
         auto it = ds.lower_bound(L);
         ans[idx] = (it != ds.end() && *it <= R);
    }

    for (int L = st[node]; L < st[node] +sz[node] && !keep ; ++L)
        ds.erase(ds.find(p[inv[L]]));

}
void main_(int tc) {
  lol



    
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    //freopen("trains.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int tt = 1, tc = 0 ; cin >> tt;
    while (tt--) main_(++tc);
    #ifndef ONLINE_JUDGE
    cout << "Running Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s .\n";
    #endif
    return 0;
}


/*
 * // Finding the second smallest element
    // in the set using * because
    //  find_by_order returns an iterator
    cout << *(o_set.find_by_order(1))
         << endl;

    // Finding the number of elements
    // strictly less than k=4
    cout << o_set.order_of_key(4)
         << endl;
 */
// sources gamed // https://ekzlib.netlify.app/view/kinetic_tournament.cpp // K seg tree
// simplification // test 1 2 3 // operation intersects ? dp // sweep line // define a function to help the dp
// reverese thinking // go from the back // drop a variable from a state to answer


// 854 abcd // E F G

/*
 *


 */

// a ( x0 + k * b/g ) + b (y0 - k * a/g ) = n
// remember void macro
// define a definition
// verify ur states
// build recurrence
//  need history ?
// deal with ranges      L <= x <= R  // make L // ex : codeton round 4 D // 846 E // toposort
// sweep line ? sort l  , r , type ? // two pointers // think interms of reverse graph //  Kosaraju’s algorithm // mn node ?? play with seg tree key
// sweep line +1 , -1 , sort type ?
// define some functions like dp let f[i] be max len right border nad so on

// euler said a ^n is congruent to a ^ (n % p-1) % p if p is prime

/*
 *
 *



ll solve (int sz , int prev , bool leading ){
    if (!sz) return 1;
    ll ret = 0;
    cout << sz <<" "<< prev <<" " <<leading<< endl;
    ret = 0;
    if (leading){
        ret = solve(sz-1 , 0 , 1);
        for (int d = 1; d < n; ++d){
            int ch2 = solve(sz-1 , d , 0);
            ret = add(ret , ch2 , mod);
        }
    }
    else{
        for (auto i : {prev-1 , prev+1}){
            if (i >= 0 && i < n){
                ll ch = solve(sz-1 , i , 0);
                ret = add(ret , ch , mod);
            }
        }
    }
    return ret;
}

///////////////////////////////////////

 *
 * #include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<int> a;

const int N= 1e5 + 10;
long long dp[N], F[N];

long long solve(int i){
    if(i >= N)
        return 0;

    long long &ret= dp[i];
    if(ret != -1)
        return ret;

    long long ch1= solve(i + 1);
    long long ch2= solve(i + 2) + 1LL * i * F[i];

    return ret= max(ch1, ch2);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);


    cin>>n;
    for(int i = 0; i < n; i++){
        int x; cin>>x;
        F[x]++;
    }
    memset(dp, -1, sizeof dp);
    cout<<solve(0);
}

 struct SegmTree {
     string name = "SegmTree";
     map<int, int> roots;

     struct Node {
         int l = 0, r = 0, sz = 0;
     };
     vector<Node> T = {{}};
     int n;

     int build(int b, int e, int pos) {
         int ret = T.size(); T.emplace_back();
         T[ret].sz = 1;

         if (b != e) {
             int m = (b + e) / 2;
             if (pos <= m) T[ret].l = build(b, m, pos);
             else T[ret].r = build(m + 1, e, pos);
         }
         return ret;
     }

     void update(int node) {
         T[node].sz = T[T[node].l].sz + T[T[node].r].sz;
     }


     pair<int, int> split(int node, int k) {
         int lsz = T[T[node].l].sz, l = node, r = T.size();
         T.emplace_back();

         if (k > lsz) tie(T[l].r, T[r].r) = split(T[l].r, k - lsz);
         else swap(T[l].r, T[r].r);
         if (k < lsz) tie(T[l].l, T[r].l) = split(T[l].l, k);
         update(l); update(r);
         return {l, r};
     }

     int merge(int a, int b) {
         if (!a or !b) return (a | b);

         T[a].l = merge(T[a].l, T[b].l);
         T[a].r = merge(T[a].r, T[b].r);
         update(a);
         return a;
     }

     SegmTree(vector<int>& V) : n(V.size()) {
         for (int i = 0; i < n; ++i)
             roots[i] = build(0, n - 1, V[i]);
         roots[n] = 0;
     }

     void split_for(int x) {
         auto it = prev(roots.upper_bound(x));
         if (it->first != x) {
             tie(it->second, roots[x]) = split(it->second, x - it->first);
         }
     }
     void Sort(int b, int e) {
         if (b == e) return;
         split_for(b); split_for(e);
         auto it = roots.find(b);

         int jn = 0;
         while (it->first != e) {
             jn = merge(jn, it->second);
             ++it; roots.erase(prev(it));
         }
         assert(T[jn].sz == (e - b));
         roots[b] = jn;
     }

     vector<int> ret;
     void dump(int node, int b, int e) {
         if (node == 0) return;
         if (b == e) { ret.push_back(b); return; }
         int m = (b + e) / 2;
         dump(T[node].l, b, m);
         dump(T[node].r, m + 1, e);
     }

     vector<int> Dump() {
         ret.clear();
         for (auto p : roots) {
             dump(p.second, 0, n - 1);
         }
         return ret;
     }
 };


 // look at my code
 // my code is amazing

 // Lets Goooooooooooooooo
 /*
 int node, R[N], ls[N << 5], rs[N << 5], sz[N << 5];
 ll val[N << 5], sum[N << 5];
 void push(int x) {
     val[x] = val[ls[x]] + val[rs[x]] + sum[ls[x]] * sz[rs[x]];
     sum[x] = sum[ls[x]] + sum[rs[x]], sz[x] = sz[ls[x]] + sz[rs[x]];
 }
 void ins(int l, int r, int p, int &x) {
     if(!x) x = ++node;
     if(l == r) return sz[x]++, sum[x] += p, void();
     int m = l + r >> 1;
     if(p <= m) ins(l, m, p, ls[x]);
     else ins(m + 1, r, p, rs[x]);
     push(x);
 }
 int merge(int l, int r, int x, int y) {
     if(!x || !y) return x | y;
     assert(l != r);
     int m = l + r >> 1;
     ls[x] = merge(l, m, ls[x], ls[y]);
     rs[x] = merge(m + 1, r, rs[x], rs[y]);
     return push(x), x;
 }

 ll n, ans, a[N], b[N], f[N], l[N], tot[N];
 int find(int x) {return f[x] == x ? x : f[x] = find(f[x]);}
 ll cal(int x) {
     ll res = l[x] * sum[R[x]] - tot[x];
     return res + val[R[x]];
 }
 void UFS(int x, int y, bool tp) {
     if(x >= N || y >= N) return;
     x = find(x), y = find(y);
     if(x == y || (!R[x] || !R[y]) && !tp) return;
     ans -= cal(x), ans -= cal(y);
     f[y] = x, l[x] = min(l[x], l[y]), tot[x] += tot[y];
     R[x] = merge(1, n, R[x], R[y]);
     ans += cal(x);
 }



 const int maxn = 200010;
 int T, n, m, u[maxn], v[maxn], w[maxn], bel[maxn * 2];
 int tim, tid[maxn * 2], id[maxn], val[maxn * 2];
 int stot, L[maxn * 2], R[maxn * 2], rt[maxn];
 int dep[maxn * 2], fa[maxn * 2][20], mxe[maxn * 2][20];
 vector<array<int, 3>> E, _E;
 vector<int> ver, G[maxn * 2];
 vector<array<int, 2>> H[maxn], ban[maxn * 2];
 set<int> S[maxn * 2];
 struct node { int l, r, s; } t[maxn * 20];

 int find(int x) {
     return x == bel[x] ? x : bel[x] = find(bel[x]);
 }

 #define mid ((l + r) >> 1)
 void ins(int &k, int l, int r, int p) {
     t[k = ++stot] = (node){0, 0, 1};
     if (l == r) return;
     mid >= p ? ins(t[k].l, l, mid, p) : ins(t[k].r, mid + 1, r, p);
 }

 int find(int k, int l, int r, int p) {
     if (t[k].s == r - l + 1) return -1;
     if (l == r) return l;
     int x = -1;
     if (mid >= p) x = find(t[k].l, l, mid, p);
     if (!~x) x = find(t[k].r, mid + 1, r, p);
     return x;
 }

 int merge(int k1, int k2) {
     if (!k1 || !k2) return k1 | k2;
     t[k1].l = merge(t[k1].l, t[k2].l);
     t[k1].r = merge(t[k1].r, t[k2].r);
     t[k1].s = t[t[k1].l].s + t[t[k1].r].s;
     return k1;
 }

 void main_(int tc) {
     scanf("%d %d", &n, &m);
     E.clear(), _E.clear();
     for (int i = 1; i <= m; i++) {
         scanf("%d %d %d", &u[i], &v[i], &w[i]);
         E.push_back({w[i], u[i], v[i]});
     }
     iota(bel + 1, bel + n + 1, 1);
     sort(E.begin(), E.end());
     for (auto &e : E) if (find(e[1]) ^ find(e[2])) {
             _E.push_back(e), bel[find(e[1])] = find(e[2]);
         }
     swap(E, _E);
     iota(bel + 1, bel + 2 * n, 1);
     for (int i = 1; i < 2 * n; i++) {
         G[i].clear();
     }
     ver.clear();
     int tot = n;
     for (auto &e : E) {
         int u = find(e[1]), v = find(e[2]);
         bel[u] = bel[v] = ++tot, ver.push_back(tot);
         val[tot] = e[0], G[tot].push_back(u), G[tot].push_back(v);
     }
     assert(tot == find(1));
     function<void(int)> init = [&](int u) {
         dep[u] = dep[fa[u][0]] + 1;
         for (int i = 1; i < 20; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
         L[u] = tim + 1;
         for (int v : G[u]) fa[v][0] = u, init(v);
         if (L[u] == tim+1) tid[u] = ++tim, id[tim] = u;
         R[u] = tim;
     };
     tim = stot = 0, fa[tot][0] = 0;
     init(tot), assert(tim == n);
     for (int i = 1; i <= n; i++) ins(rt[i], 1, n, i);
     for (int i = 1; i <= tot; i++) {
         ban[i].clear();
     }
     for (int i = 1; i <= m; i++) {
         int x = u[i], y = v[i];
         if (dep[x] < dep[y]) swap(x, y);
         for (int j = 19; ~j; j--) {
             if (dep[fa[x][j]] >= dep[y]) x = fa[x][j];
         }
         if (x == y) { ban[x].push_back({u[i], v[i]}); continue; }
         for (int j = 19; ~j; j--) {
             if (fa[x][j] ^ fa[y][j]) x = fa[x][j], y = fa[y][j];
         }
         ban[fa[x][0]].push_back({u[i], v[i]});
     }
     sort(ver.begin(), ver.end(), [&](int x, int y) { return val[x] < val[y]; });
     iota(bel + 1, bel + n + 1, 1);
     for (int i = 1; i <= n; i++) {
         H[i].clear();
     }
     for (int x : ver) {
         assert(G[x].size() == 2);
         for (auto &p : ban[x]) {
             S[tid[p[0]]].insert(tid[p[1]]), S[tid[p[1]]].insert(tid[p[0]]);
         }
         if (R[G[x][0]] - L[G[x][0]] > R[G[x][1]] - L[G[x][1]]) swap(G[x][0], G[x][1]);
         for (int i = L[G[x][0]]; i <= R[G[x][0]]; i++) {
             int l = L[G[x][1]], r = R[G[x][1]];
             while (l <= r) {
                 int y = find(rt[find(i)], 1, n, l);
                 if (!~y || y > r) break;
                 if (S[i].count(y)) { l = y + 1; continue; }
                 H[id[i]].push_back({id[y], val[x]});
                 H[id[y]].push_back({id[i], val[x]});
                 rt[find(y)] = merge(rt[find(y)], rt[find(i)]); // small to large
                 bel[find(i)] = find(y);
             }
         }

         for (auto &p : ban[x]) {
             S[tid[p[0]]].erase(tid[p[1]]), S[tid[p[1]]].erase(tid[p[0]]);
         }
     }
     function<void(int)> rdfs = [&](int u) {
         dep[u] = dep[fa[u][0]] + 1;
         for (int i = 1; i < 20; i++) {
             fa[u][i] = fa[fa[u][i - 1]][i - 1];
             mxe[u][i] = max(mxe[u][i - 1], mxe[fa[u][i - 1]][i - 1]);
         }
         for (auto &e : H[u]) if (e[0] ^ fa[u][0]) {
                 fa[e[0]][0] = u, mxe[e[0]][0] = e[1], rdfs(e[0]);
             }
     };
     fa[1][0] = mxe[1][0] = 0, rdfs(1);
     for (int i = 1; i <= m; i++) {
         int x = u[i], y = v[i], ans = 0;
         if (dep[x] < dep[y]) swap(x, y);
         for (int j = 19; ~j; j--) {
             if (dep[fa[x][j]] >= dep[y]) ans = max(ans, mxe[x][j]), x = fa[x][j];
         }
         if (x == y) { printf("%d%c", ans, " \n"[i == m]); continue; }
         for (int j = 19; ~j; j--) if (fa[x][j] ^ fa[y][j]) {
                 ans = max({ans, mxe[x][j], mxe[y][j]});
                 x = fa[x][j], y = fa[y][j];
             }
         ban[fa[x][0]].push_back({u[i], v[i]});
         ans = max({ans, mxe[x][0], mxe[y][0]});
         printf("%d%c", ans, " \n"[i == m]);
     }

 }


 /*

 string ass (string & s) {
     s += s;
     int n = (int)s.size();
     int i = 0, ans = 0;
     while (i < n / 2) {
         ans = i;
         int j = i + 1, k = i;
         while (j < n && s[k] <= s[j]) {
             if (s[k] < s[j])
                 k = i;
             else
                 k++;
             j++;
         }
         while (i <= k)
             i += j - k;
     }
     return s.substr(ans, n / 2);


 }














 x3 - w3 >= x2 + w2
 x3 - w3 >= x1 + w1
 x2 - w2 >= x1 + w1

 //https://www.hackerrank.com/contests/world-codesprint-13/challenges/dynamic-trees




 ll mul (ll a, ll b , ll m){
     return ( ( a % m ) * ( b % m ) ) % m;
 }
 ll add (ll a , ll b , ll m){
     return (a + b + m ) % m;
 }
 ll Fp (ll b , ll p , ll m){
     if (!p) return 1;
     ll v = Fp(b , p >> 1 , m);
     v = mul(v , v , m);
     if (p & 1) v = mul(v , b , m);
     return v;
 }
 ll modInv(ll b , ll m){
     return Fp(b , m-2 , m);
 }


 struct dragon{
     vector < vector <ll > > t; int n;
     vector <ll > a ;
     void S (int _n , vector <ll> & b){
         n = _n +5;
         while (popcount(n) != 1) ++n;
         t = vector < vector <ll > > (2 *n);
         a = b;
         build(0 , 0 , n);
     }
     vector <ll > merge (vector <ll> & u , vector <ll> & v){
         vector <ll> ans;
         int szu = (int)u.size();
         int szv = (int)v.size();
         int L  , R; L = R = 0;
         while (L < szu || R < szv){
             if (L > szu) ans.emplace_back(v[R++]);
             else if (R > szv) ans.emplace_back(u[L++]);
             else if (u[L] > v[R]) ans.emplace_back(v[R++]);
             else ans.emplace_back(u[L++]);
         }
         return ans;
     }
     void build (int node , int nl , int nr){
         if (nr - nl == 1){
             if (nl < (int)a.size()) t[node].emplace_back(a[nl]);
             return;
         }
         int mid = nl + nr >> 1;
         build(2* node +1 , nl , mid);
         build(2* node +2 , mid , nr);
         t[node] = merge(t[2* node +1] , t[2* node +2]);
     }

     ll query (int node , int nl , int nr ,int ql , int qr , ll val){
         if (nl >= qr || ql >= nr) return 0;
         if (nl >= ql && qr >= nr) return upper_bound(all(t[node]) , val)- t[node].begin();
         int mid = nl + nr >> 1;
         ll ans = query(2 * node +1 , nl , mid , ql , qr , val);
         ans+= query(2* node +2 , mid , nr , ql , qr , val);
         return ans;
     }

     ll query (ll l , ll r , ll val){
         return query(0 , 0 , n , l , r+1 , val);
     }

 };





 struct dsu {
     vector <int > par , sz; int n;
     void init(int _n){
         n = _n +10;
         par = sz = vector <int > (n +10 , 1);
         iota(all(par) , 0);
     }
     int findp (int node){
         if (node == par[node]) return node;
         return par[node] = findp(par[node]);
     }
     bool _union(int u , int v){
         u = findp(u); v= findp(v);
         if (u == v) return 0;
         if (sz[u] < sz[v]) swap(u , v);
         par[v] = u;
         sz[u]+= sz[v];
         return 1;
     }
 };

 ll nck (ll n , ll k){
    ll ans , kk; ans = 1 , kk = 2; if (k > n) return 0; k = min(k , n-k);
     for (ll l = n - k+1; l <= n ; ++l){
         ans = ans * l ; if (kk <= k && ans % kk == 0) ans/=kk++;
     }
     return ans;
 }

 ll Fp (ll a, ll p){
     if (!p) return 1;
     ll v = Fp(a , p >> 1);
     v = mul(v , v);
     if (p & 1) v= mul(v , a);
     return v;
 }

 ll fact[N+10];
 ll modInv (ll n){
     return Fp(n , mod-2);
 }
 void init(){
     fact[0] = 1;
     // inv in faster way
     for (ll i = 1; i <=1e6+10; ++i) fact[i] = mul(fact[i-1] , i);
 }

 ll npr(ll n , ll r){// fact[n]/ fact[n-r]
     if (r > n|| r < 0) return 0;
     return mul(fact[n] , modInv(fact[n-r]));
 }
 ll ncr (ll n , ll r){ // fact[n]/ fact[r] * fact[n-r]
     if (r > n|| r < 0) return 0;
     return mul(npr(n , r), modInv(fact[r]));
 }
 struct dragon{
     vector <int > t; int n;
     void init (int _n){
         n = _n; while (popcount(n) != 1) ++n;
         t = vector <int > (2 * n);
     }
     void upd(int node , int nl , int nr , int idx , int val){
         if (nr - nl == 1) { t[node]+= val; return;}
         int mid = nl + nr >> 1;
         if (idx < mid) upd(2* node +1 , nl , mid , idx , val);
         else upd(2* node +2 , mid , nr , idx , val);
         t[node] = t[2 * node +1] + t[2* node +2];
     }
     void upd (int idx , int val){ return upd(0 , 0 , n , idx , val);}

     int query (int node , int nl , int nr , int ql , int qr){
         if (nl >= qr || ql >= nr) return 0;
         if (nl >= ql && qr >= nr) return t[node];
         int mid = nl + nr >> 1;
         int ans = query(2 * node +1 , nl , mid , ql , qr);
         ans+= query(2* node +2 , mid , nr , ql , qr);
         return ans;
     }
     int query (int l , int r){ return l <= r ?query(0 , 0 , n , l , r+1) : 0;}

 };


 int freq[N];


 */