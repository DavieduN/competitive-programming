// https://codeforces.com/problemset/problem/1843/F1

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
    vector<int> curmn (n+2), curmx (n+2), mx (n+2), mn (n+2);
    curmx[1] = mx[1] = 1;
    int idx=1;
    for (int i=0; i<n; i++){
        char op;
        int a, b, c;
        cin >> op >> a >> b;
        if (op == '+'){
            idx++;
            curmx[idx] = max(curmx[a]+b, 0);
            curmn[idx] = min(curmn[a]+b, 0);
            mx[idx] = max(mx[a], curmx[idx]);
            mn[idx] = min(mn[a], curmn[idx]);
        }
        else{
            cin >> c;
            if (mn[b] <= c && c <= mx[b]) cout << "YES";
            else cout << "NO";
            cout << '\n';
        }
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