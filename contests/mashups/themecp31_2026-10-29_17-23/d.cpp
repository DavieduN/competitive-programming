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

#define int long long

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

    vector<vector<ll>> cnt (n, vector<ll>(10));
    /* 
    0: empty
    1: 2
    2: 20
    3: 202
    4: 202 5
    5: 202 6
    6: 202 5 6
    */

    for (int i=0; i<n; i++){
        for (int j=0; j<7; j++) if (i) cnt[i][j] = cnt[i-1][j];
        cnt[i][0]++;
        if (s[i] == '5'){
            cnt[i][6] += cnt[i][5];
            cnt[i][5] = 0;
            cnt[i][4] += cnt[i][3];
            cnt[i][3] = 0;  
        }
        if (s[i] == '6'){
            cnt[i][6] += cnt[i][4];
            cnt[i][4] = 0;
            cnt[i][5] += cnt[i][3];
            cnt[i][3] = 0; 
        }
        if (s[i] == '2'){
            cnt[i][3] += cnt[i][2];
            cnt[i][2] = 0;
            cnt[i][1] += cnt[i][0];
            cnt[i][0] = 0;
        }
        if (s[i] == '0'){
            cnt[i][2] += cnt[i][1];
            cnt[i][1] = 0;
        }

        ll ans = (i+1) * (n-i);


        ans -= (cnt[i][4]) * (nxt[i][6] - i); // 202 5
        int l = nxt[i][5], r = nxt[i][6];
        if (l < r) ans -= (cnt[i][3]) * (r-l); // 202
        int j = nxt[i][2];
        l = nxt[j][5], r = nxt[j][6];
        if (l < r) ans -= (cnt[i][2]) * (r-l); // 20
        j = nxt[nxt[i][0]][2];
        l = nxt[j][5], r = nxt[j][6];
        if (l < r) ans -= (cnt[i][1]) * (r-l); // 2
        j = nxt[nxt[nxt[i][2]][0]][2];
        l = nxt[j][5], r = nxt[j][6];
        if (l < r) ans -= (cnt[i][0]) * (r-l); // 2

        cout << ans << ' ';
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