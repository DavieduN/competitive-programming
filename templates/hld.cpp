#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define ld long double
#define sz(a) ((int)a.size())

void dbg_out(string s) {cerr << endl; }
template<typename H, typename ... T>
void dbg_out(string s, H h, T ... t){
    do {cerr << s[0]; s = s.substr(1);
    } while(s.size() && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

template<class T> class LazySeg{
public:
    int n;
    vector<T> t, lazy;
    void init(int nn){
        n=1;
        while (n<nn) n <<= 1;
        t.resize(2*n);
        lazy.resize(2*n);
    }
    T comb(T l, T r){
        return l + r;
    }

    void apply(int idx){
        t[idx] = -t[idx];
        lazy[idx] = 0;
    }

    void prop(int idx){
        if (!lazy[idx]) return;
        if (idx < n){
            lazy[2*idx] ^= lazy[idx];
            lazy[2*idx+1] ^= lazy[idx];
        }
        apply(idx);
    }

    T update(int l, int r, int idx, int a, int b){
        prop(idx);
        if (b < l || r < a) return 0;
        if (a <= l && r <= b){
            lazy[idx] ^= 1;
            prop(idx);
            return t[idx];
        }
        T ans=0;
        int m = (l+r)/2;
        ans = comb(update(l, m, 2*idx, a, b), update(m+1, r, 2*idx+1, a, b));
        t[idx] = comb(t[2*idx], t[2*idx+1]);
        return ans;
    }

    void set(int idx, T v){
        if (idx < 0 || idx >= n) return;
        t[idx+=n] = v;
        for (idx >>= 1; idx; idx >>=1) t[idx] = comb(t[2*idx], t[2*idx+1]);
    }

    T update(int l, int r){
        return update(0, n-1, 1, l, r);
    }
};

// USE ZERO-INDEXED, add edges then init
// for any path, at most 2log(n) heavy chains + light edges
// can be used similar to sqrt decomposition
// "process methods" give indices for external data structure to use through Op
template<bool VALS_IN_EDGES> class HLD{
public:
    int N, R;
    vector<vector<int>> adj;
    vector<int> par, root, depth, tot, pos;
    int ti;
    vector<int> rpos; // rpos not used but could be useful, stores who is the node in pos[i]

    HLD(int n): N (n), adj(n), par(n), root(n), depth(n), tot(n), pos(n){}
    void ae(int x, int y) { adj[x].push_back(y), adj[y].push_back(x); }
    void dfsSz(int x){
        tot[x] = 1;
        for (auto& y: adj[x]){
            par[y] = x;
            depth[y] = depth[x]+1;
            adj[y].erase(find(all(adj[y]),x)); // remove parent from adj list
            dfsSz(y);
            tot[x] += tot[y];
            if (tot[y] > tot[adj[x][0]]) swap(y,adj[x][0]); // adj[i][0] is heavy edge
        }
    }
    void dfsHld(int x){
        pos[x] = ti++;
        rpos.push_back(x);
        for (auto y: adj[x]){
            root[y] = (y == adj[x][0] ? root[x] : y);
            dfsHld(y);
        }
    }
    void init(int _R = 0){
        R = _R;
        par[R] = depth[R] = ti = 0;
        dfsSz(R);
        root[R] = R;
        dfsHld(R);
    }

    // op(int l, int r, bool is_going_down), bool only for non-commutative
    // O(nlogn * O(op))
    template <class Op>
    void processPath(int x, int y, Op op){
        bool rev = false;
        stack<pair<int, int>> st;
        for (; root[x] != root[y]; y = par[root[y]]) {
            if (depth[root[x]] > depth[root[y]]) swap(x,y), rev = !rev;
            if (rev) op(pos[root[y]], pos[y], 0);
            else st.emplace(pos[root[y]], pos[y]);
        }

        if (depth[x] > depth[y]) swap(x,y), rev = !rev;

        int l = pos[x]+VALS_IN_EDGES, r = pos[y];
        if (l <= r){
            if (rev) op(l, r, 0);
            else st.emplace(l, r);
        }

        while (!st.empty()){
            op(st.top().first, st.top().second, 1);
            st.pop();
        }
    }
    
    template <class Op>
    void processSubtree(int x, Op op){
        int l = pos[x] + VALS_IN_EDGES;
        int r = pos[x] + tot[x] - 1;
        if (l <= r) op(l, r);
    }

    template <class Op>
    void processPoint(int x, Op op){
        op(pos[x]);
    }

    // climbs to root, for every light edge calls op(node, parent)
    template <class Op>
    void climbLightEdges(int x, Op op) {
        while (root[x] != R) {
            int node = root[x];
            int parent = par[node];
            op(node, parent); // passing nodes and not pos[node]
            x = parent;
        }
    }

    int lca(int x, int y) {
        for (; root[x] != root[y]; y = par[root[y]])
            if (depth[root[x]] > depth[root[y]]) swap(x,y);
        return depth[x] < depth[y] ? x : y;
    }
    int dist(int x, int y){ // # edges on path
        return depth[x]+depth[y]-2*depth[lca(x,y)];
    }
};




void solution(){
    int n, q;
    cin >> n >> q;
    vector<tuple<int, int, int>> edges;
    HLD<1> hld (n);
    LazySeg<ll> seg;
    for (int i=0; i<n-1; i++){
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        hld.ae(a, b);
        edges.emplace_back(a, b, w);
    }
    hld.init(0);
    seg.init(n);

    for (auto [a, b, w]: edges){
        if (hld.par[b] == a) swap(a, b);
        hld.processPoint(a, [&](int x){
            seg.set(x, -w);
        });
    }

    ll ans=0;
    while (q--){
        int a, b;
        cin >> a >> b;
        a--, b--;
        hld.processPath(a, b, [&](int l, int r, bool flag){
            ans += seg.update(l, r);
        });
        cout << ans << '\n';
    }
}

signed main(){
    fastio;
    int cases = 1;
    //cin>> cases;

    for (int i = 0; i < cases; i++)
    {
        solution();
    }
    
}