// https://codeforces.com/problemset/problem/1907/E

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


ll cnt[10][3];
ll memo[10][10][10];

void go(int a, int b, int c){
    if (a+b+c == 10 || memo[a][b][c]) return;
    memo[a][b][c] = 1;

    cnt[a+b+c][0]++;
    if (a == b) cnt[a+b+c][1]++;
    
    go(a+1, b, c);
    go(a, b+1, c);
    go(a, b, c+1);
}

void solution(){
    string n;
    cin >> n;

    ll cur = 1;
    for (auto c: n){
        int x = c-'0';
        cur *= cnt[x][0];
    }

    cout << cur << '\n';
}

signed main(){
    fastio;
    memset(cnt, 0, sizeof(cnt));
    memset(memo, 0, sizeof(memo));
    go(0, 0, 0);
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}