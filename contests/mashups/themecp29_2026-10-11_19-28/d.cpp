// https://codeforces.com/problemset/problem/2005/C

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

const int mx = 5;
string ord = "narek";

void solution(){
    int n, m;
    cin >> n >> m;
    vector<int> best (mx, -n*m-1000);
    best[0] = 0;
    for (int i=0; i<n; i++){
        string s;
        cin >> s;
        vector<int> nbest = best;
        for (int j=0; j<mx; j++){
            int cur = j;
            int delta = 0;
            for (auto c: s){
                if (c == ord[cur]){
                    cur++;
                    if (cur == mx){
                        delta += 5;
                        cur = 0;
                    }
                }
                else if (c == 'n' || c == 'a' || c == 'r' || c == 'e' || c == 'k'){
                    delta--;
                }
            }
            dbg(i, j, cur, delta);
            nbest[cur] = max(nbest[cur], best[j]+delta);
        }
        best = nbest;
    }
    int ans=0;
    for (int i=0; i<mx; i++) ans = max(ans, best[i]-i);
    cout << ans << "\n";
}

signed main(){
    fastio;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}