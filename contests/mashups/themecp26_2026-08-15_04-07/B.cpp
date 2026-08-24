// https://codeforces.com/problemset/problem/1851/D

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
    vector<ll> psum (n-1);
    for (auto& x: psum) cin >> x;

    vector<int> cnt (2*n);
    ll prev=0;
    for (auto x: psum){
        ll a = x-prev;
        if (a > 2*n-1){
            cout << "NO\n";
            return;
        }
        prev = x;
        cnt[a]++;
    }
    vector<int> missing, extra;
    for (int i=1; i<2*n; i++){
        if (!cnt[i] && i <= n) missing.push_back(i);
        int res=0;
        if (i > n && cnt[i]) res = cnt[i];
        else if (i <= n && cnt[i] >= 2) res = cnt[i]-1;
        while (res--) extra.push_back(i);
    }
    if (sz(extra) > 1) cout << "NO";
    else if (sz(extra) == 1) cout << ((sz(missing) == 2 && missing[0]+missing[1] == extra[0])? "YES" : "NO");
    else cout << ((sz(missing) == 1)? "YES" : "NO");
    cout << "\n";
}

signed main(){
    fastio;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}