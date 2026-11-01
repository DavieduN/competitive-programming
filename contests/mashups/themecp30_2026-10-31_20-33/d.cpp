// https://codeforces.com/problemset/problem/2262/A2

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

const ll M = 1e9+7;

void solution(){
    int n;
    cin >> n;
    vector<int> mx_l (n+1, -1), rem (n+2);
    for (int i=1; i<=n; i++){
        int mex;
        cin >> mex;
        for (int j=0; j<n; j+=i){
            int l = j;
            int r = min(j+i-1, n-1);
            if (j/i == mex){
                rem[l]++;
                rem[r+1]--;
                break;
            }
            mx_l[r] = max(mx_l[r], l);
        }
    }
    vector<ll> dp (n+1), psum (n+2);
    int cur=0, lim=-1;
    for (int i=0; i<=n; i++){
        cur += rem[i];
        if (!cur){
            if (lim == -1) dp[i] = (psum[i] + 1) % M;
            else dp[i] = (psum[i] - psum[lim] + M) % M;
        }
        psum[i+1] = (psum[i] + dp[i]) % M;
        lim = max(lim, mx_l[i]);
    }
    cout << dp[n] << '\n';
}

signed main(){
    fastio;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}