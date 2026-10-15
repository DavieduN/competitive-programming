// https://codeforces.com/problemset/problem/1844/C

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

ll inf = -1e17;

void solution(){
    int n;
    cin >> n;
    ll best[2] = {0, 0};
    ll mx=inf;
    for (ll i=0, x; i<n; i++){
        cin >> x;
        if (x > 0) best[i&1] += x;
        mx = max(x, mx);
    }
    ll ans = max(best[0], best[1]);
    if (mx < 0) ans = mx;
    cout << ans << '\n';
}

signed main(){
    fastio;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}