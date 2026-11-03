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

const ll M = 1e9+7;

void solve(){
    int k, n;
    ll L;
    cin >> k >> L;
    vector<vector<ll>> d (k, vector<ll>(k));
    for (int i=0; i<k; i++){
        for (int j=0; j<k; j++){
            cin >> d[i][j];
        }
    }
    cin >> n;
    vector<int> a (n+1);
    for (int i=0; i<n-1; i++){
        cin >> a[i];
    }
    vector<vector<ll>> dp (n+1, vector<ll>(k+1)), arr (n+1, vector<ll>(k+1));
    arr[0][0] = 1;
    ll ans=0;
    for (int i=0; i<n-1; i++){
        ll cur=0;
        for (int j=0; j<k; j++){
            cur = (cur + arr[i][j]) % M;
            dp[i][j] = cur;
            int l = lower_bound(all(d[j]), a[i]-L) - d[j].begin();
            int r = upper_bound(all(d[j]), a[i]+L) - d[j].begin();
            arr[i+1][l] = (arr[i+1][l] + dp[i][j]) % M;
            arr[i+1][r] = (arr[i+1][r] - dp[i][j] + M) % M;
        }
    }
    ll cur=0;
    for (int i=0; i<k; i++){
        cur = (cur + arr[n-1][i]) % M;
        ans = (ans + cur) % M;
    }
    cout << ans << '\n';
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
}