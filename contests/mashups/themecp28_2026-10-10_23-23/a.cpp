// https://codeforces.com/problemset/problem/1834/C

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

// by parity of bob's moves:
// even: a == b
// odd: rev(a) == b

void solution(){
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int x=0, y=0;
    for (int i=0; i<sz(a); i++) if (a[i] != b[i]) x++;
    reverse(all(a));
    for (int i=0; i<sz(a); i++) if (a[i] != b[i]) y++;
    if (y == 0) y = 1;
    cout << min(2*x-(x%2), 2*y-(y%2==0)) << '\n';
}

signed main(){
    fastio;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}