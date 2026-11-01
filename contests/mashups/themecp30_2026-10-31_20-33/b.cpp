// https://codeforces.com/problemset/problem/2276/D

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


const int mx = 3e5+123;
vector<int> g[mx];
int vis[mx];
void dfs(int x){
    if (vis[x]) return;
    vis[x] = 1;
    for (auto y: g[x]) dfs(y);
}

void solution(){
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        g[i].clear();
        vis[i] = 0;
    }
    vector<int> deg (n+1);
    for (int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        deg[a]++, deg[b]++;
    }
    queue<int> q;
    for (int i=1; i<=n; i++){
        if (deg[i] == 0){
            cout << "Brain Melt\n";
            return;
        }

        if (deg[i] == 1) q.push(i);
    }

    while (!q.empty()){
        int u = q.front(); q.pop();
        deg[u]--;
        for (auto v: g[u]){
            deg[v]--;
        }
    }

    int comp=0;
    bool many=false;
    for (int i=1; i<=n; i++){
        if (!vis[i]){
            comp++;
            dfs(i);
        }
        if (deg[i] > 0) many = true;
    }

    many |= (comp > 1);
    cout << (many ? "Many" : "2") << '\n'; 
}

signed main(){
    fastio;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}