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
    int n;
    cin >> n;
    vector<int> a (n);
    vector<pair<int, int>> arr (n);
    for (int i=0; i<n; i++){
        cin >> a[i];
        arr[i] = {a[i], i};
    }
    sort(rall(arr));
    set<int> s;
    s.insert(-2*n);
    s.insert(3*n);
    vector<int> ans (n+1);
    for (auto [_, i]: arr){
        auto it = s.lower_bound(i);
        int r = *it;
        int l = *(--it);
        l = max((i+l)/2+1, 0);
        r = min((i+r+1)/2-1, n-1);
        
        if (l <= r){
            ans[l]++;
            ans[r+1]--;
        }
        s.insert(i);
    }
    int cur=0;
    for (int i=0; i<n; i++){
        cur += ans[i];
        cout << cur-1 << ' ';
    }
    cout << '\n';
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
}