// https://codeforces.com/problemset/problem/2027/D1

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

const int inf = 1e9;

void solution(){
    int n, m;
    cin >> n >> m;
    vector<int> a (n), b (m);
    for (auto& x: a) cin >> x;
    for (auto& x: b) cin >> x;
    vector<vector<int>> best (n+1, vector<int>(m, inf));
    best[0] = vector<int>(m);
    vector<ll> r (m), tot (m);
    for (int i=0; i<n; i++){
        int cur=inf;
        for (int j=0; j<m; j++){
            cur = min(cur, best[i][j]);
            while (r[j] < n && tot[j]+a[r[j]] <= b[j]) tot[j] += a[r[j]++];
            best[r[j]][j] = min(best[r[j]][j], cur+m-j-1);
        }
        for (int j=0; j<m; j++) tot[j] -= a[i];
    }
    int ans=inf;
    for (int i=0; i<m; i++) ans = min(ans, best[n][i]);
    cout << (ans == inf? -1 : ans) << '\n';
}

signed main(){
    fastio;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}