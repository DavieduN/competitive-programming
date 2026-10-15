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

void solve(int n, int x){
    vector<int> a (n);
    for (int i=1; i<=n; i++){
        if (i < 10) cout << ' ';
        cout << i << ' ';
    }
    cout << '\n';
    for (int i=1; i<=n; i++){
        a[i-1] = x^i;
        if (a[i-1] < 10) cout << ' ';
        cout << a[i-1] << ' ';
    }
    cout << '\n';
    sort(all(a));
    for (auto k: a){
        if (k < 10) cout << ' ';
        cout << k << ' ';
    }
    cout << '\n';
}

void solution(){
    int n, x;
    cin >> n >> x;
    for (int i=1; i<=n; i++){
        cout << i << "====\n";
        solve(i, x);
    }
}

signed main(){
    fastio;
    int cases=1;
    //cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}