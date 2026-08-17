// https://codeforces.com/problemset/problem/2003/D1

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
    ll n, m;
    cin >> n >> m;
    vector<pair<int, int>> arr;
    ll mxl=0;
    for (int i=0, l; i<n; i++){
        cin >> l;
        mxl = max(mxl, (ll)l);
        vector<int> tmp (l);
        for (auto& x: tmp) cin >> x;
        sort(all(tmp));
        int mex=0, used=0;
        int a, b=-1;
        for (auto x: tmp){
            if (x == mex) mex++;
            else if (x < mex) continue;
            else if (used) break;
            else{
                used = 1;
                a = mex;
                mex++;
                if (x == mex) mex++;
            }
        }
        b = mex;
        if (!used) a = mex, b = mex+1;
        arr.push_back({a, b});
        dbg(a, b);
    }
    ll k = mxl+2;
    vector<int> indeg (k), best (k);
    vector<vector<int>> g (k);
    for (auto [a, b]: arr){
        g[b].push_back(a);
        indeg[a]++;
    }
    queue<int> q;
    for (int i=0; i<k; i++){
        best[i] = i;
        if (!indeg[i]) q.push(i);
    }
    while (!q.empty()){
        auto x = q.front(); q.pop();
        for (auto y: g[x]){
            indeg[y]--;
            best[y] = max(best[x], best[y]);
            if (!indeg[y]) q.push(y);
        }
    }

    int sbest=0;
    for (auto [a, b]: arr){
        dbg(a, best[a]);
        sbest = max(sbest, best[a]);
    }
    dbg(sbest);

    ll ans=0;
    for (int i=0; i<min(k, m+1); i++) ans += max(best[i], sbest);

    dbg(ans);
    dbg(k, m);

    if (m > k) ans += m * (m+1) - k * (k-1);
    cout << ans << '\n';
}

signed main(){
    fastio;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}