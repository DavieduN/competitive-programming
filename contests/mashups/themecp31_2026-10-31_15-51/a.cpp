// https://codeforces.com/problemset/problem/2273/A

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

    int l=1, r=n, ans=r;
    while (l<=r){
        int m = l + (r-l)/2;

        ll tot=0;
        for (int i=1; i<=m; i++){
            tot += m/i * i;
        }

        if (tot >= n){
            ans = m;
            r = m-1;
        }
        else l = m+1;
    }

    cout << ans << '\n';
    vector<int> needs (n+1);
    for (int i=1; i<=ans; i++){
        needs[i] = ans/i;
    }
    int target=ans;
    int cnt=0;
    int cur=1;
    for (int i=1; i<=n; i++){
        if (!needs[target]) target--;
        cout << cur << ' ';
        if (++cnt == target){
            cnt = 0;
            needs[target]--;
            cur++;
        }
    }
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