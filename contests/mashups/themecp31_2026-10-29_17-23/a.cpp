// https://codeforces.com/problemset/problem/2275/D

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

const ll inf = 1e18+1e18;

void solution(){
    ll n, k;
    cin >> n >> k;
    vector<tuple<ll, ll, ll>> arr (n);
    vector<ll> cost (n), tot (n);
    ll limit = inf;
    for (int i=0; i<n; i++){
        auto& [a, b, c] = arr[i];
        cin >> a >> b >> c;
        if (a == b && a == c){
            cost[i] = -1;
            limit = min(limit, a+b+c);
        }
        else if (a > b || a > c || b > c) cost[i] = 0;
        else if (a == b || b == c) cost[i] = 1;
        else cost[i] = min(b-a+1, c-b+1);
        tot[i] = a+b+c;
    }

    auto f = [&](ll x) -> bool {
        if (x > limit) return false;
        ll cur=0;
        for (int i=0; i<n; i++){
            if (cost[i] == -1) continue;
            if (tot[i] >= x) continue;
            cur += x - tot[i] + 2*cost[i];
            if (cur > k) return false;
        }
        return true;
    };

    ll l=-1e10, r=inf;
    ll ans = l;
    while (l<=r){
        ll m = l + (r-l)/2;
        if (f(m)){
            l = m+1;
            ans = m;
        }
        else r = m-1;
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