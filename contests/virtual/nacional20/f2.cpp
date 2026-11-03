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


const ll inf = 1e17;
const int mx = 8001;

ll dp[mx][mx];

void solve(){
    int n;
    cin >> n;
    vector<int> a (n), bef (n, -1);
    stack<pair<int, int>> st;
    for (int i=0; i<n; i++){
        cin >> a[i];
        while (!st.empty()){
            auto [x, j] = st.top();
            if (x <= a[i]){
                st.pop();
            }
            else{
                bef[i] = j;
                break;
            }
        }
        st.push({a[i], i});
    }

    for (int i=0; i<n; i++) dp[i][0] = inf;

    stack<pair<ll, short>> s;
    for (int j=1; j<=n; j++){
        for (int i=0; i<n; i++){
            if (bef[i] == -1) dp[i][j] = (j == 1? a[i] : inf);
            else dp[i][j] = dp[bef[i]][j];

            ll cur=inf;
            while (!s.empty()){
                auto [tot, idx] = s.top();
                if (a[idx] <= a[i]){
                    cur = min({cur, tot, dp[idx][j-1]});
                    s.pop();
                }
                else{
                    cur = min(cur, dp[idx][j-1]);
                    break;
                }
            }

            dp[i][j] = min(dp[i][j], cur + a[i]);
            
            s.push({cur, i});
        }
        while (!s.empty()) s.pop();
    }

    sort(rall(a));
    ll ans2=0;
    for (int i=1; i<=n; i++){
        ans2 += a[i-1];
        cout << dp[n-1][i] << ' ' << ans2 << '\n';
    }

}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
}