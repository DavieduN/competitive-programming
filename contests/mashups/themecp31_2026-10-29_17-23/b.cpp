// https://codeforces.com/problemset/problem/2275/E

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
    int n;
    cin >> n;
    vector<int> a (n), b (n);
    for (auto& x: a) cin >> x;
    for (auto& x: b) cin >> x;
    int tot = (a.back() == b.back()? 2 : 1);
    for (int i=0; i+1<n; i++){
        tot += 2 + (a[i] == b[i+1]) + (b[i] == a[i+1]);
    }
    int ans = tot;
    int cur=0;
    for (int i=0; i<n; i++){
        ans = max(ans, tot+cur);
        if (i+1 < n) cur += (a[i] == b[i]? 2 : 1) - (a[i] == b[i+1]? 2 : 1);
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