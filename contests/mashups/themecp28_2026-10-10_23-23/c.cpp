// https://codeforces.com/problemset/problem/1899/F

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
    int n, q;
    cin >> n >> q;
    for (int i=1; i+1<=n; i++){
        cout << i << " " << i+1 << '\n';
    }
    int cur = n-1;
    while (q--){
        int d;
        cin >> d;
        if (d == cur) cout << "-1 -1 -1\n";
        else{
            cout << n << ' ' << cur << ' ' << d << '\n';
            cur = d;
        }
    }
}

signed main(){
    fastio;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}