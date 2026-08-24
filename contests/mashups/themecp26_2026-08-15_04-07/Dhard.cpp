// https://codeforces.com/problemset/problem/2044/G1

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

void solution(){
    int n;
    cin >> n;
    vector<int> deg (n+1), nxt (n+1), v (n+1, 1);
    for (int i=0, x; i<n; i++){
        cin >> x;
        deg[x]++;
        nxt[i+1] = x;
    }
    int ans=0;
    queue<pair<int, int>> q;
    for (int i=1; i<=n; i++) if (!deg[i]) q.push({i, 1});
    while (!q.empty()){
        auto [x, d] = q.front(); q.pop();
        ans = max(ans, v[x]);
        v[nxt[x]] += v[x];
        deg[nxt[x]]--;
        if (!deg[nxt[x]]) q.push({nxt[x], d+1});
    }
    cout << ans+2 << '\n';
}

signed main(){
    fastio;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}