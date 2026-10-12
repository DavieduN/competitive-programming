// https://codeforces.com/problemset/problem/1971/F

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
    ll r;
    cin >> r;
    ll r2=r*r, r12=(r+1)*(r+1);
    ll ans = 0;
    for (ll y=1; y<r; y++){
        // sqrt (x² + y²) = r | r+1
        // x²+y² = r² | (r+1)²
        // x² = r²|(r+1)² - y²
        ll a = r2 - y*y;
        ll sa = sqrt(a);
        if (sa*sa < a) sa++;

        ll b = r12 - y*y;
        ll sb = sqrt(b);
        if (sb*sb < b) sb++;

        ans += sb-sa;
    }
    ans *= 4;
    ll x2 = r12-r2;
    ll x = sqrt(x2);
    ll a = -x, b = x;
    if (x*x < x2) b++;
    else a++;
    ans += 2*(b-a);
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