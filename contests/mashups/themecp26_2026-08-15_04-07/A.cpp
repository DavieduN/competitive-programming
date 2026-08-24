// https://codeforces.com/problemset/problem/1933/D

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
    vector<int> a (n);
    int mn=1e9+123, cnt=0;
    for (int i=0; i<n; i++){
       cin >> a[i];
       if (a[i] < mn) mn = a[i], cnt=1;
       else if (a[i] == mn) cnt++; 
    }
    bool can=false;
    for (auto x: a) if (x%mn) can = true;
    cout << ((cnt == 1 || can)? "YES" : "NO") << '\n';
}

signed main(){
    fastio;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}