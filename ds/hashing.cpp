ll p1[N], p2[N] , inv[N] , inv2[N];
void init(){
    p2[0] = inv2[0] = p1[0] = inv[0] = 1;
    ll Inv = modInv(P1 , mod);
    ll Inv2 = modInv(P2 , mod2);
    for (ll i = 1; i <= 4e5; ++i){
        p1[i] = mul(p1[i-1] , P1 , mod);
        inv[i] = mul(inv[i-1] , Inv , mod);
        p2[i] = mul(p2[i-1] , P2 , mod2);
        inv2[i] = mul(inv2[i-1] , Inv2 , mod2);
    }
}
struct Hash{
    int n;
    vector <array<ll,2 > > pre;
    void build(string & s){
        n = (int)s.size();
        pre = vector <array<ll,2 > > (n+5);
        pre[0][0] = pre[0][1]= s[0] - 'a'+1;
        for (int i = 1; i < n; ++i){
            pre[i][0] = add(pre[i-1][0] , mul(s[i]-'a'+1 , p1[i] , mod) , mod);
            pre[i][1] = add(pre[i-1][1] , mul(s[i]-'a'+1 , p2[i] , mod2) , mod2);
        }
    }
    array<ll , 2 > query(ll l , ll r){ // zero based inclusive
        array<ll,2 > ans;
        ans[0] = add(pre[r][0] , (l ? -pre[l-1][0] : 0) , mod);
        ans[1] = add(pre[r][1] , (l ? - pre[l-1][1] : 0) , mod2);
        ans[0] = mul(ans[0] , inv[l] , mod);
        ans[1] = mul(ans[1] , inv2[l] , mod2);
        return ans;
    }
 
};
 
