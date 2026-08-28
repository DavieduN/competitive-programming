// https://codeforces.com/problemset/problem/2147/C

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
    bool can=true;
    for (int i=0; i+2<n; i++) if (s[i] == '0' && s[i+1] == '1' && s[i+2] == '1') s[i] = 'l';
    for (int i=n-3; i>=0; i--) if (s[i] == '1' && s[i+1] == '1' && s[i+2] != '1'){
        if (s[i+2] == 'l') can = false;
        s[i+2] = 'r';
    }
    for (int i=0; i+1<n; i++) if (s[i] == 'r' && s[i+1] == '1'){
        if (i+2 == n || s[i+2] == 'r' || s[i+2] == '1') can = false;
        if (i+2 < n) s[i+2] = 'l';
    }
    for (int i=n-1; i-1>=0; i--) if (s[i-1] == '1' && s[i] == 'l'){
        if (i-1 == 0 || s[i-2] == 'l' || s[i-2] == '1') can = false;
        if (i-1) s[i-2] = 'r';
    }
    vector<pair<int, int>> arr;
    for (int i=0; i<n; i++) if (s[i] == '0'){
        if (i && i+1 < n && s[i-1] != '1' && s[i+1] != '1') continue; // is not border
        else if ((i && s[i-1] != '1') || (i+1 < n && s[i+1] != '1')) arr.push_back({i, 1}); // border, any side
        else if (i == 0 || i == n-1) arr.push_back({i, 1}); // array border
        else arr.push_back({i, 0});
    }
    int cur=0, solved=0, lst=-5;
    for (auto [a, b]: arr){
        if (lst+2 == a){
            cur++;
            solved += b;
        }
        else{
            if (!solved && cur%2==1) can = false;
            cur = 1;
            solved = b;
        }
        lst = a;
    }
    if (!solved && cur%2==1) can=false;
    cout << (can? "YES" : "NO") << '\n';
}

signed main(){
    fastio;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}