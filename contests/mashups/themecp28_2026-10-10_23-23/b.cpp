// https://codeforces.com/problemset/problem/1904/C

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
    int n, k;
    cin >> n >> k;
    vector<ll> a (n);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    
    if (k >= 3){
        cout << 0 << '\n';
        return;
    }
    
    sort(all(a));
    ll ans=a[0];
    for (int i=0; i+1<n; i++){
        ans = min(ans, a[i+1]-a[i]);
    }

    if (k == 2){
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                ll x = a[j]-a[i];
                ans = min(ans, x);

                int r = upper_bound(all(a), x) - a.begin();
                int l = max(r-1, 0);

                if (r < n) ans = min(ans, a[r]-x);
                ans = min(ans, (a[l] <= x? x-a[l] : a[l]-x));
            }
        }
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