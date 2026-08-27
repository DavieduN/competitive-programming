// https://codeforces.com/problemset/problem/1918/C

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
    ll a, b, r;
    cin >> a >> b >> r;
    ll x = 0;
    for (ll i=60; i>=0; i--){
        if ((a>>i&1) == (b>>i&1)) continue;
        if (r < (x | (1ll<<i))) continue;
        if (b > a) swap(a, b); // a >= b
        if ((a>>i&1) && (a^(1ll<<i)) > (b^(1ll<<i))){
            a ^= 1ll<<i;
            b ^= 1ll<<i;
            x ^= 1ll<<i;
        }
    }
    cout << abs(a-b) << '\n';
}

signed main(){
    fastio;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}