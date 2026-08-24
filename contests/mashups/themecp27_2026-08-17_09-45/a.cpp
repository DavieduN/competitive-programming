// https://codeforces.com/problemset/problem/2021/B

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
    int n, x;
    cin >> n >> x;
    vector<int> a (n);
    vector<int> ctr (min(n, x));
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(all(a));
    int mex=0;
    int cur=0;
    for (int i=0; i<n; i++){
        while (cur < n && a[cur] <= i) ctr[a[cur++]%x]++;
        if (ctr[i%x]) ctr[i%x]--, mex++;
        else break;
    }
    cout << mex << '\n';
}

signed main(){
    fastio;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}