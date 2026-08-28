// https://codeforces.com/problemset/problem/2060/E

#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do{ cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

class DSU{
  public:
    int n;
    vector<int> p, r, s;
 
    DSU(int nodes): p (nodes), r (nodes, 1), s (nodes, 1){
        n = nodes;
        for (int i=0; i<n; i++) p[i] = i;
    }
	  /*
    ll find(ll x){
        return (p[x] == x? x : p[x] = find(p[x]));
    }
    */
    int find(int x){
        int root=x;
        while (root != p[root]) root = p[root];
        int aux;
        while (x != p[x]){
            aux = p[x];
            p[x] = root;
            x = aux;
        }
        return x;
    }
 
    bool unite(int x, int y){
        x = find(x), y = find(y);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x, y);
        if (r[x] == r[y]) r[y]++;
        s[y] += s[x];
        p[x] = y;
        n--;
        return true;
    }
 
};

void solution(){
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<vector<int>> g (n);
    vector<pair<int, int>> edges (m1);
    for (auto &[a, b]: edges) cin >> a >> b;
    DSU dsu (n);
    for (int i=0; i<m2; i++){
        int a, b;
        cin >> a >> b;
        dsu.unite(--a, --b);
    }
    int ans=0;
    DSU dsu2 (n);
    for (auto [a, b]: edges){
        --a, --b;
        if (dsu.find(a) == dsu.find(b)) dsu2.unite(a, b);
        else ans++;
    }
    cout << ans + (dsu2.n - dsu.n) << '\n';
}

signed main(){
    fastio;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}