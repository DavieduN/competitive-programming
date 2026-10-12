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
    ll ans=0;
    for (ll y=1; y<r; y++){
        // sqrt (x² + y²) = r | r+1
        // x²+y² = r² | (r+1)²
        // x² = r²|(r+1)² - y²
        ll a = r2 - y*y;
        ll b = r12 - y*y;
        //ll dist2 = b-a;
        ll x1 = sqrt(a);
        ll x2 = sqrt(b);

        if (x1*x1 == a) ans++;
        else if (x2*x2 < b) ans++;
    }
    ans *= 8;
    if (2*r*r < r12) ans += 4;
    cout << ans+4 << '\n';
}

signed main(){
    fastio;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}