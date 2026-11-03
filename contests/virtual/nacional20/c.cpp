#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do{
        cerr << s[0];
        s = s.substr(1);
    }
    while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif


void solve(){
    int n;
    cin >> n;
    vector<ll> a (n);
    ll tot=0, v=0;
    for (int i=0; i<n; i++){
        cin >> a[i];
        tot+=a[i];
    }
    v = tot/n;
    ll cur=0, ans=1e17, glass=0;
    vector<ll> b = a;
    for (int i=0; i<2*n; i++){
        int idx = i%n;
        cur += glass;
        if (b[idx] > v){
            glass += b[idx] - v;
            b[idx] = v;
        }
        else{
            ll spend = min(v-b[idx], glass);
            glass -= spend;
            b[idx] += spend; 
        }
    }
    ans = cur;
    b = a;
    cur=0, glass=0;
    for (int i=2*n-1; i>=0; i--){
        int idx = i%n;
        cur += glass;
        if (b[idx] > v){
            glass += b[idx] - v;
            b[idx] = v;
        }
        else{
            ll spend = min(v-b[idx], glass);
            glass -= spend;
            b[idx] += spend; 
        }
    }
    ans = min(ans, cur);
    cout << ans << '\n';
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
}