#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do{
        cerr << s[0];
        s = s.substr(1);
    }
    while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

void solve(){
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> arr (n);
    for (int i=0; i<n; i++){
        cin >> arr[i].first >> arr[i].second;
        arr[i].second += arr[i].first;
    }
    sort(all(arr));
    int ans=-1, best=1e9+123;
    for (int i=0; i<481; i++){
        int m = i%x;
        int cur=0;
        for (auto [a, b]: arr){
            if (i > b) continue;
            a = max(a, i);
            int l=a;
            if (a%x < m) l = a + m - a%x;
            else if (a%x > m) l = a + x-a%x + m;
            cur += (b-l+1+x-1)/x;

            if (i < 2){
                dbg(a, b);
                dbg(l);
            }
        }
        if (i < 2){
            dbg(cur);
        }
        if (cur < best){
            best = cur;
            ans = i;
        }
    }
    cout << ans << ' ' << best << '\n';
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
}