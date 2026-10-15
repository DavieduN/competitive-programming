// https://codeforces.com/problemset/problem/1860/B

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
    ll m, k, a1, ak;
    cin >> m >> k >> a1 >> ak;

    // no k coins
    ll l = max(0ll, m-a1);
    ll ans = l;
    if (k > m){
        cout << ans << '\n';
        return;
    }
    

    ll mnk = (l+k-1)/k, mxk = m/k;
    if (mnk <= mxk) ans = min(ans, max(mnk-ak, 0ll));
    else{
        mnk = max(0ll, mnk-1);
        ans = min(ans, max(mnk-ak, 0ll) + l - mnk*k);
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