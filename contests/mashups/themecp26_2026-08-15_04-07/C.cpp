// https://codeforces.com/problemset/problem/2050/E

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

const int inf = 1e9;

void solution(){
    string a, b, c;
    cin >> a >> b >> c;
    vector<vector<int>> dp (sz(a)+1, vector<int>(sz(b)+1, inf));
    dp[0][0] = 0;
    for (int i=0; i<sz(c); i++){
        for (int j=0, k=i+1; j<=min(sz(a), i+1); j++, k--){
            if (k > sz(b)) continue;
            if (j) dp[j][k] = min(dp[j][k], dp[j-1][k]+(a[j-1]!=c[i]));
            if (k) dp[j][k] = min(dp[j][k], dp[j][k-1]+(b[k-1]!=c[i]));
        }
    }
    cout << dp[sz(a)][sz(b)] << '\n';
}

signed main(){
    fastio;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}