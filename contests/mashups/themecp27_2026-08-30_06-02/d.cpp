// https://codeforces.com/problemset/problem/1822/G1

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

const int MX = 1e6+1;
vector<ll> cnt (MX), used (MX), fat (MX);

void solution(){
    int n;
    cin >> n;
    vector<ll> a (n);
    ll mx=0;
    for (auto& x: a){
        cin >> x;
        cnt[x]++;
        mx = max(mx, x);
    }
    ll ans=0;
    for (auto x: a){
        if (used[x]) continue;
        used[x] = 1;
        if (cnt[x] >= 3) ans += cnt[x]*(cnt[x]-1)*(cnt[x]-2);
        for (ll i=2; i*i*x<=mx; i++){
            ans += cnt[x] * cnt[x*i] * cnt[x*i*i];
        }
    }
    cout << ans << '\n';

    for (auto x: a) cnt[x] = used[x] = 0;
}

signed main(){
    fastio;

    fat[0] = 1;
    for (ll i=1; i<MX; i++) fat[i] = fat[i-1]*i;

    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}