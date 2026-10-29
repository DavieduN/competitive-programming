// https://codeforces.com/problemset/problem/2258/B2

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
    int n, m;
    cin >> n >> m;
    vector<int> cnt (m+1);
    for (int i=0, x; i<n; i++){
        cin >> x;
        cnt[x]++;
    }
    vector<ll> psum (m+2);
    for (int i=0; i<=m; i++) psum[i+1] = psum[i]+cnt[i];
    vector<ll> ans (m);
    for (int f=1; f<=m; f++){
        ll cur=0;
        int p=1;
        for (int c=1; c*f<=m; c++){
            if (c+1 > (1<<p)) p++;
            int r = min(m+1, (c+1)*f);
            cur += (psum[r]-psum[c*f]) * c;
            ans[p-1] = max(ans[p-1], cur + (psum[m+1]-psum[r])*c + ((c+1)*f <= m ? cnt[(c+1)*f] : 0));
        }
    }
    ll mx=0;
    for (auto a: ans){
        mx = max(mx, a);
        cout << mx << ' ';
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