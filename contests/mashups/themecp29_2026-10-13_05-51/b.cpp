// https://codeforces.com/problemset/problem/2162/D

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

ll query(int op, int l, int r){
    cout << op << ' ' << l+1 << ' ' << r+1 << endl;
    ll ans;
    cin >> ans;
    return ans;
}

ll diff(int l, int r){
    return query(2, l, r) - query(1, l, r);
}

pair<int, int> solve(int l, int r, ll tot){
    if (r-l+1 == tot){
        return {l, r};
    }
    int m = l + (r-l)/2;
    ll x = diff(l, m);
    if (x == 0) return solve(m+1, r, tot);
    else if (x == tot) return solve(l, m, tot);
    else{
        return {m-x+1, tot-x+m};
    }
}

void solution(){
    int n;
    cin >> n;
    ll tot = diff(0, n-1);
    auto [l, r] = solve(0, n-1, tot);
    cout << "! " << l+1 << ' ' << r+1 << endl;
}

signed main(){
    //fastio;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}