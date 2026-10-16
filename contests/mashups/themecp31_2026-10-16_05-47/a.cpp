// https://codeforces.com/problemset/problem/2254/D

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
    map<ll, ll> cnt, mp;
    vector<ll> arr (n);
    for (int i=0; i<n; i++){
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    vector<pair<ll, ll>> vals;
    for (auto [a, b]: cnt) vals.push_back({a, b});
    reverse(all(vals));
    bool can=true;
    if (vals.back().first != 0) can = false;
    for (int i=0; i+1<sz(vals); i++){
        auto [a, b] = vals[i];
        auto [x, y] = vals[i+1];
        ll diff = a-x;
        if (diff%y) can = false;
        ll v = diff/y;
        if (v >= mp[a]){
            if (i) can = false;
            else mp[a] = v+1;
        }
        mp[x] = v;
    }
    auto [a, b] = vals[0];
    if (sz(vals) == 1) mp[a] = 1;

    if (can) for (auto x: arr) cout << mp[x] << ' ';
    else cout << -1;
    cout << '\n';
}

signed main(){
    fastio;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}