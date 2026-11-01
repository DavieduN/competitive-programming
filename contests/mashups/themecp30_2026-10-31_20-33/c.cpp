// https://codeforces.com/problemset/problem/2255/B

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

const int mx = 1e6+123;
const ll M = 998244353;
ll fac[mx];

ll fast_exp(ll a, ll b){
    ll ans=1;
    while (b){
        if (b&1) ans = ans * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return ans;
}

ll choose(ll a, ll b){
    if (a < 0 || b < 0) return 1;
    return fac[a] * fast_exp(fac[b], M-2)%M * fast_exp(fac[a-b], M-2)%M;
}

void solution(){
    int n;
    cin >> n;
    ll G[2] = {0, 0}, cnt[2] = {0, 0};
    char last = 'a'; 
    for (int i=0; i<n; i++){
        char c;
        cin >> c;
        if (c != last) G[c-'0']++;
        cnt[c-'0']++;
        last = c;
    }
    cout << choose(cnt[0]-1, G[0]-1) * choose(cnt[1]-1, G[1]-1) % M << '\n';
}

signed main(){
    fastio;
    fac[0] = 1;
    for (ll i=1; i<mx; i++) fac[i] = fac[i-1] * i % M;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}