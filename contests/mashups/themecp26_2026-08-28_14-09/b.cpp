// https://codeforces.com/problemset/problem/1973/B

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
    vector<int> a (n);
    int tot=0;
    for (int i=0; i<n; i++){
        cin >> a[i];
        tot |= a[i];
    }
    vector<int> cnt (20);
    int r=-1, cur=0, mx=1;
    for (int l=0; l<n; l++){
        while (cur != tot){
            r++;
            if (r == n) break;
            for (int i=0; i<20; i++) if (a[r]>>i&1){
                cnt[i]++;
                cur |= 1<<i;
            }
        }
        if (r == n){
            mx = max(mx, n-l+1);
            break;
        }
        mx = max(mx, r-l+1);
        for (int i=0; i<20; i++) if (a[l]>>i&1){
            cnt[i]--;
            if (!cnt[i]) cur ^= 1<<i;
        }
    }
    cout << mx << '\n';
}

signed main(){
    fastio;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}