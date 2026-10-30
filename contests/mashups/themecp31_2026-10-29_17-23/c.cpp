// https://codeforces.com/problemset/problem/2258/C

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
    
    int a=1, b=2, cur=0;

    auto query = [&](int x, int y) -> void {
        int ans=1;
        while (ans){
            cout << "? " << x << ' ' << y << ' ' << cur+1 << endl;
            cin >> ans;
            if (ans){
                a = x;
                b = y;
                cur++;
            }
        }
    };
    
    for (int i=1; i<=n; i++){
        if (i == a) continue;
        query(a, i);
    }
    swap(a, b);
    for (int i=1; i<=n; i++){
        if (i == a) continue;
        query(a, i);
    }

    cout << "! " << a << ' ' << b << ' ' << cur << '\n';
}

signed main(){
    // fastio;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}