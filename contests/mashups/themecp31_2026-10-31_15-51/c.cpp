// https://codeforces.com/problemset/problem/2257/D

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


ll solve(ll x, ll y, vector<ll>& div, ll tot){
    int idx = lower_bound(all(div), x) - div.begin();
    dbg(x, y, tot, idx);
    ll ans=0;
    if (idx < sz(div)){
        ll a = min(x, div[idx]);
        ll b = min(y, tot/div[idx]);
        ans = max(ans, a*b);
    }
    idx--;
    if (idx >= 0){
        ll a = min(x, div[idx]);
        ll b = min(y, tot/div[idx]);
        ans = max(ans, a*b);
    }
    return ans;
}

void solution(){
    ll s, q;
    cin >> s >> q;
    vector<ll> A, tmp;
    for (ll i=1; i*i<=s; i++){
        if (s%i) continue;
        A.push_back(i);
        if (s/i != i) tmp.push_back(s/i);
    }
    for (int i=sz(tmp)-1; i>=0; i--) A.push_back(tmp[i]);
    vector<ll> B (sz(A));
    for (int i=0; i<sz(A); i++) B[i] = s/A[i];

    vector<ll> psum (sz(A)+1);
    for (int i=0; i<sz(A); i++){
        ll d = A[i] - (i? A[i-1] : 0);
        psum[i+1] = psum[i] + d * B[i]; 
    }

    for (int i=0; i<q; i++){
        ll x, y;
        cin >> x >> y;

        ll l=0, r=sz(B)-1, ans=0;
        while (l<=r){
            int m = l + (r-l)/2;
            if (y <= B[m]){
                ans = m;
                l = m+1;
            }
            else r = m-1;
        }

        if (x <= A[ans]){
            cout << x*y << '\n';
            continue;
        }

        ll tot = A[ans] * y;

        int idx = upper_bound(all(A), x) - A.begin();
        idx--;

        if (idx >= 0 && idx >= ans+1){
            tot += psum[idx+1] - psum[ans+1];
        }

        int idx2 = lower_bound(all(A), x) - A.begin();
        l = idx, r = idx2;
        tot += (x - A[l]) * B[r];

        cout << tot << '\n';
    }
}

signed main(){
    fastio;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}