// https://codeforces.com/problemset/problem/2039/C2

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

ll div_range(ll a, ll b, ll x){
    return b/x + 1 - (a+x-1)/x - (a <= x && x <= b);
}


void solution(){
    ll x, m;
    cin >> x >> m;
    ll cntx=0, cnty=0;
    for (ll y=1; y<=min(x, m); y++){
        ll z = x^y;
        if (z%x==0) cntx++;
        else if (z%y==0) cnty++;
    }
    if (m <= x){
        dbg(cntx, cnty);
        cout << cntx+cnty << '\n';
        return;
    }
    dbg(cnty);
    ll ans = cnty;

    ll cur=0;
    for (ll i=62; i>=0; i--) if (m>>i&1){
        ll a = (x^cur)>>(i);
        dbg(i, cur, a);
        a <<= i;
        ll b = (x^cur) | ((1ll<<i)-1);
        
        ll v = div_range(a, b, x);
        dbg(a, b, v);
        ans += v;

        cur |= 1ll<<i;
    }
    if ((m^x)%x == 0) ans++;

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