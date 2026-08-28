// https://codeforces.com/problemset/problem/1868/A

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
    int n, m;
    cin >> n >> m;
    cout << (m == 1? 0 : min(m, n+1)) << '\n';
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (i >= m-1) cout << (j+1)%m << ' ';
            else cout << (j+m-1-i)%m << ' ';
        }
        cout << '\n';
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