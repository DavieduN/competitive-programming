// https://codeforces.com/gym/106598/problem/L

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
    vector<int> p (n), pos (n);
    for (int i=0; i<n; i++){
        cin >> p[i];
    }
    vector<vector<int>> dp (n, vector<int>(n));
    for (int l=n-1; l>=0; l--){
        for (int r=l+2; r<n; r++){
            vector<int> tmp;
            for (int i=0; i<n; i++) if (l <= p[i] && p[i] <= r){
                pos[p[i]] = sz(tmp);
                tmp.push_back(p[i]);
            }
            int cur = 0;
            for (int i=l+1; i<r; i++){
                // LX[R]R
                // L[L]XR

                int a=0, b=0;
                if (pos[i-1]){
                    if (pos[i-1]-1 != pos[i]) a = (tmp[pos[i-1]-1] < i ? -1 : 1);
                    else if (pos[i-1]-1) a = (tmp[pos[i-1]-2] < i ? -1 : 1);
                }
                if (pos[i-1]+1 < sz(tmp)){
                    if (pos[i-1]+1 != pos[i]) b = (tmp[pos[i-1]+1] < i ? -1 : 1);
                    else if (pos[i-1]+2 < sz(tmp)) b = (tmp[pos[i-1]+2] < i ? -1 : 1);
                }
                // add a L

                // a == 0 && b == 0: impossible
    
                // a == -1 
                // b == -1: 0 (else) L[L]L
                // b == 0: 0 (else) L[L]|
                // b == 1: 0 (else) L[L]R

                // a == 1
                // b == -1: 0 (else) R[L]L
                // b == 0: 1 (if) R[L]|
                // b == 1: 2 (else if) R[L]R

                if (a == 0) swap(a, b);
                if (!b && a == 1) cur++;
                else if (a == b && a == 1) cur += 2;

                a=0, b=0;
                if (pos[i]){
                    if (pos[i]-1 != pos[i-1]) a = (tmp[pos[i]-1] < i-1 ? -1 : 1);
                    else if (pos[i]-1) a = (tmp[pos[i]-2] < i-1 ? -1 : 1);
                }
                if (pos[i]+1 < sz(tmp)){
                    if (pos[i]+1 != pos[i-1]) b = (tmp[pos[i]+1] < i-1 ? -1 : 1);
                    else if (pos[i]+2 < sz(tmp)) b = (tmp[pos[i]+2] < i-1 ? -1 : 1);
                }

                 // remove a R

                // a == 0 && b == 0: impossible
    
                // a == -1 
                // b == -1: -2 (else if) L[R]L
                // b == 0: -1 (if) L[R]|
                // b == 1: 0 (else) L[R]R

                // a == 1
                // b == -1: 0 (else) R[R]L
                // b == 0: 0 (else) R[R]|
                // b == 1: 0 (else) R[R]R

                if (a == 0) swap(a, b);
                if (!b && a == -1) cur--;
                else if (a == b && a == -1) cur -= 2;

                dp[l][r] = max(dp[l][r], dp[l][i-1]+dp[i+1][r]+cur);

                dbg(l, r, i, cur);
            }
        }
    }
    cout << dp[0][n-1] << '\n';
}

signed main(){
    fastio;
    int cases=1;
    //cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}