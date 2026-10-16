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
    ll n, m;
    cin >> n >> m;
    vector<int> cnt (m+1);
    for (int i=0, x; i<n; i++){
        cin >> x;
        cnt[x]++;
    }
    vector<int> psum (1);
    for (int i=1; i<=m; i++) psum.push_back(psum.back()+cnt[i]);
    vector<ll> ans (m+1), best (m+1);
    ll p=1;
    for (ll k=1; k<=min(m, 20ll); k++){
        p <<= 1;
        for (ll f=1; p/2*f<=m; f++){
            for (ll x = p/2*f; x+f-1 <= min(p*f-1, m); x += f){
                best[f] += (psum[min(x+f-1, m)]-psum[x-1])*(x/f);
            }
            ll extra = (psum.back() - psum[min(p*f-1, m)])*(p-1);
            ll tot = best[f] + extra + (p*f <= m? cnt[p*f] : 0);
            ans[k] = max(ans[k], tot);
        }
    }
    ll cur=0;
    for (int i=1; i<=m; i++){
        cur = max(cur, ans[i]);
        cout << cur << ' ';
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