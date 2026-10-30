// https://codeforces.com/problemset/problem/2276/E

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
    string s;
    cin >> s;

    vector<vector<ll>> nxt (n+1, vector<ll>(10));
    for (int j=0; j<10; j++) nxt[n][j] = n;
    for (int i=n-1; i>=0; i--){
        for (int j=0; j<10; j++) nxt[i][j] = nxt[i+1][j];
        nxt[i][s[i]-'0'] = i;
    }

    vector<ll> d1 (n+2), d2 (n+2);
    ll cur2=0, cur1=0;
    for (int i=0; i<n; i++){
        int j = nxt[nxt[nxt[i][2]][0]][2];
        int l = nxt[j][5], r = nxt[j][6];
        if (l < r){
            d1[i] += r-l;
            d2[l+1] -= 1;
            d2[r+1] += 1;
        }
        cur2 += d2[i];
        d1[i] += cur2;
        cur1 += d1[i];
        cout << (i+1ll)*(n-i) - cur1 << ' ';
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