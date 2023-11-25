#include <bits/stdc++.h>


using namespace std;
#define ll long long
#define ld long double
#define F first
#define S second
#define endl '\n'
#define Tsetso ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const int N = 3e5+10, M = 23, inf = 1e6, mod = 1e9+7;
vector <ll > v;

ll Ex_gcd(ll a , ll b , ll & x0 , ll& y0){

    auto nxt= [&] (ll &a , ll &b , ll q)-> void{
        ll next = a - q* b;
        a = b ;
        b = next;
    };
    ll r0 = a , r1 = b;
    ll x1 , y1;
    x0 = y1 = 1;
    y0 = x1 = 0;
    while (r1){
        ll q = r0/ r1;
        nxt(r0 , r1 , q);
        nxt(x0 , x1 , q);
        nxt(y0 , y1 , q);
    }
    return r0;
}

ll LDE(ll a , ll b , ll c ,ll& x0 , ll& y0){
    ll g = Ex_gcd(abs(a) , abs(b) , x0 , y0);// be careful use abs
    if (c%g){
        return -1;
    }
    x0*= c/g;
    y0*= c/g;
    a >= 0 ? x0*=1 : x0*=-1;
    b >= 0 ? y0*=1 : y0*=-1;
    return g;
}

pair<pair<ll,ll>,pair<ll,ll>>  num_of_solutions(ll a , ll b , ll c , ll mnx , ll mxx, ll mny , ll mxy){
    ll x , y;
    ll g = LDE(a , b  , c , x , y);
    if (g == -1){
        return {{0 , -1}, {-1 , -1}};
    }
    //x0 = x+ k * b/ g
    //y0 = y- k* a/g
    a = abs(a); b = abs(b); // x and y contain this sign
    ll lx , rx ,ly , ry; a/=g; b/= g;
    lx = mnx , rx =mxx; ly = mny , ry = mxy;
    // mnx -x0 <= k * b <= mxx- x0
    // (mnx-x0)/b <= k <= (mxx-x0)/b
    lx = ceil((mnx-x) *1.0/ b);
    rx = floor((mxx-x)*1.0 / b);
    // mny <= y- k *a <= mxy
    // (mny-y) <= - k * a <= (mxy-y)
    // (-mny+y) >=  k * a >=  (-mxy+y)
    ry = floor((y-mny)*1.0 / a);
    ly = ceil((y-mxy) *1.0 / a);
    ll L = max(ly , lx);
    ll R = min(ry , rx);
    //  cout <<L<<' '<<"i    "<<R<<" uuuuuuuuu "<<lx<<" "<<rx<<"  tttttt  "<<ly<<' '<<ry<<nd;
    if (L > R) return {{0 , -1}, {-1 , -1}};
    return {{R-L+1 ,x+ L * b} , {L , R}};
};
void testCase() {
    int n ;
    cin >> n;
    ll sum = 0;
    for ( int i = 0 ; i < n ;i++)
    {
        int a , b;
        cin >> a >> b;
        sum += a;
        v.push_back(b-a);
    }
    sort(v.begin(),v.end());
    v.push_back(0);
    reverse(v.begin(),v.end());
    for ( int i = 1;  i <= n;  i++)
        v[i] += v[i-1];
    int m ;
    cin >> m ;
    for ( int i = 0 ; i < m ; i++)
    {
        int x , y;
        cin >> x >> y;
        auto p = num_of_solutions(x , y , n , 0 , n , 0 , n);
        if(!p.first.first){
            cout << "-1\n";
            continue;
        }
        ll X = p.first.first, st = p.second.first , en = p.second.second , ans = 0;
        ll Y;


        ll g = LDE(x , y , n , X , Y), b = y;
        while(st <= en)
        {
            ll m1 = st + (en - st) / 3;
            ll m2 = en - (en - st) / 3;
            ll newX = X + m1 * b / g;
            ll newX2 = X+ m2 * b / g;
            ll ans1 = sum + v[n-newX * x ];
            ll ans2 = sum + v[n-newX2 * x];
            ans = max(ans1,ans2);
            if(ans1 > ans2)
                en = m2-1;
            else
                st = m1+1;
        }
        cout << ans << '\n';
    }

}
int32_t main()
{
    Tsetso
    int tc = 1;
//    cin >> tc;
    while(tc--)
        testCase();
}
