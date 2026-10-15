// https://codeforces.com/problemset/problem/1935/C

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

const ll inf = 1e15;

void solution(){
    int n, l;
    cin >> n >> l;
    vector<pair<ll, ll>> arr (n);
    for (int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        arr[i] = {b, a};
    }
    sort(all(arr));
    int ans=0;
    vector<ll> dp (n+1, inf);
    dp[0] = 0;
    for (auto [b, a]: arr){
        for (int i=n; i>=1; i--){
            ll v = dp[i-1]+a;
            if (v+b <= l) ans = max(ans, i);
            dp[i] = min(dp[i], v);
        }
        dp[1] = min(dp[1], -b+a);
        if (a <= l) ans = max(ans, 1);
    }
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