// https://codeforces.com/problemset/problem/2148/E

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
    int n, k;
    cin >> n >> k;
    vector<int> cnt (n+1), arr (n), cur (n+1);
    for (int i=0; i<n; i++){
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    bool can=true;
    for (int i=0; i<=n; i++) if (cnt[i]%k) can=false;
    ll ans=0;
    ll r=0;
    for (ll l=0; l<n; l++){
        r = max(l, r);
        while (r < n && cur[arr[r]] < cnt[arr[r]]/k) cur[arr[r++]]++;
        ans += r-l;
        cur[arr[l]]--;
    }

    cout << (can? ans : 0) << '\n';
}

signed main(){
    fastio;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}