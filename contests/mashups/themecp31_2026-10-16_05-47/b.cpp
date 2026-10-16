// https://codeforces.com/problemset/problem/2259/E

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
    vector<int> arr (n), treasure (n), lazy (n+1);
    for (int i=0; i<n; i++){
        cin >> arr[i];
        if (arr[i] == -1) continue;
        int l=i-arr[i], r=i+arr[i];
        if (l >= 0) treasure[l] = 1;
        if (r < n) treasure[r] = 1;
        l = max(0, l+1);
        r = min(r, n);
        if (l > r) continue;
        lazy[l]++;
        lazy[r]--;
    }
    int cannot=0;
    for (int i=0; i<n; i++){
        cannot += lazy[i];
        if (cannot) treasure[i] = 0;
    }
    bool can=true;
    for (int i=0; i<n; i++) if (arr[i] != -1){
        int l=i-arr[i], r=i+arr[i];
        int cnt=0;
        if (l >= 0) cnt += treasure[l];
        if (r < n) cnt += treasure[r];
        if (!cnt) can = false;
    }
    int tot=0;
    for (auto a: treasure) tot += a;
    if (tot == 0) for (auto& a: treasure) a = 1;
    if (can) for (auto a: treasure) cout << a;
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