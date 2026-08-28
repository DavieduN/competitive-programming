// https://codeforces.com/problemset/problem/1843/D

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

void dfs(int u, int p, vector<vector<int>>& g, vector<int>& ans){
    for (auto v: g[u]) if (v != p){
        dfs(v, u, g, ans);
        ans[u] += ans[v];
    }
    if (u != p && sz(g[u]) == 1) ans[u] = 1;
}

void solution(){
    int n;
    cin >> n;
    vector<vector<int>> g (n);
    vector<int> ans (n);
    for (int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        g[--a].push_back(--b);
        g[b].push_back(a);
    }
    dfs(0, 0, g, ans);
    int q;
    cin >> q;
    while (q--){
        int a, b;
        cin >> a >> b;
        cout << (ll) ans[--a] * ans[--b] << '\n';
    }
}

signed main(){
    fastio;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}