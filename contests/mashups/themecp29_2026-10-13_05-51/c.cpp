// https://codeforces.com/problemset/problem/2082/B

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

ll g_min(int x, int n, int m){
    while (x > 1 && m){
        x = (x+1)/2;
        m--;
    }
    while (x && n){
        x /= 2;
        n--;
    }
    return x;
}

ll g_max(int x, int n, int m){
    while (x && n){
        x /= 2;
        n--;
    }
    while (x > 1 && m){
        x = (x+1)/2;
        m--;
    }
    return x;
}

void solution(){
    int x, n, m;
    cin >> x >> n >> m;
    cout << g_min(x, n, m) << ' ' << g_max(x, n, m) << '\n';
}

signed main(){
    fastio;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}