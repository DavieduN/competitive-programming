// https://codeforces.com/problemset/problem/1829/H

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

const int mv = 64, mb = 6, mn = 2e5+123;
const int M = 1e9+7;

ll p2[mn];


ll f(ll x){
    return (p2[x]-1+M)%M;
}

void solution(){
    vector<ll> cnt (mv);
    int n, k;
    cin >> n >> k;
    for (int i=0; i<n; i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    vector<ll> dp (1<<mb);
    for (int i=0; i<mv; i++){
        for (int j=0; j<mv; j++){
            int y = (j&i);
            dp[y] = (dp[y] + f(cnt[i]) * dp[j] % M) % M;
        }
        dp[i] = (dp[i] + f(cnt[i]))%M;
    }
    ll ans=0;
    for (int x=0; x<mv; x++) if (__builtin_popcount(x) == k){
        dbg(x, dp[x]);
        ans = (ans + dp[x])%M;
    }
    cout << ans << '\n';
}

signed main(){
    fastio;
    p2[0] = 1;
    for (int i=1; i<mn; i++) p2[i] = p2[i-1]*2%M;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}