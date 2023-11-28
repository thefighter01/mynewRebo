struct sss{
    // take care of data types and neutral elements and merge function
    int n;
    vector < int > t;
    void init(int _n){
        n = _n + 5;
        while (popcount(n) != 1) ++n;
        t = vector < int > (2 * n , -1);
    }
    int merge (int u, int v){
        return u & v;
    }
    void upd (int node , int nl , int nr , int idx , int v , int k){
        if (nl + 1 == nr){
            if ((k & v) == k) t[node] = v;
            return;
        }
        int md = (nl + nr) >> 1;
        if (idx < md) upd(2 * node + 1 , nl , md , idx, v, k);
        else upd(2* node + 2 , md, nr, idx, v ,k);
        t[node] = merge (t[2* node + 1] , t[2* node + 2]);
    }
    int query (int node , int nl , int nr , int ql , int qr){
        if (nl >= ql && qr >= nr) return t[node];
        int md = (nl + nr ) >> 1;
        if (qr <= md) return query(2* node + 1 , nl , md , ql ,qr);
        if (ql >= md) return query (2* node + 2, md, nr , ql ,qr);
        return merge(query (2* node + 1 , nl , md , ql ,qr), query (2 * node + 2, md, nr , ql , qr));
    }
    void upd (int idx , int v , int k){
        upd(0 , 0 , n , idx , v, k);
    }
    int query (int L , int R){
        return query (0 ,0 , n , L , R+ 1);
    }
};