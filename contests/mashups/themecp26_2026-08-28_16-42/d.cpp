// https://codeforces.com/problemset/problem/1983/D

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
    set<int> s;
    map<int, int> mp;
    vector<int> p1 (n), p2 (n);
    for (int i=0; i<n; i++){
        cin >> p1[i];
        s.insert(p1[i]);
    }

    for (int i=0; i<n; i++){
        cin >> p2[i];
        s.insert(p2[i]);
    }

    if (sz(s) != n){
        cout << "NO\n";
        return;
    }
    int cur=0;
    for (auto x: s){
        mp[x] = cur++;
    }
    for (int i=0; i<n; i++) p1[i] = mp[p1[i]], p2[i] = mp[p2[i]];

    vector<int> used (n);
    int par1=0;
    for (int i=0; i<n; i++){
        if (used[i]) continue;
        int tot = 1;
        int x = p1[i];
        used[x] = 1;
        while (p1[x] != p1[i]){
            x = p1[x];
            used[x] = 1;
            tot++;
        }
        par1 ^= (tot-1)%2;
    }
    used = vector<int>(n);
    int par2=0;
    for (int i=0; i<n; i++){
        if (used[i]) continue;
        int tot = 1;
        int x = p2[i];
        used[x] = 1;
        while (p2[x] != p2[i]){
            x = p2[x];
            used[x] = 1;
            tot++;
        }
        par2 ^= (tot-1)%2;
    }
    dbg(par1, par2);
    cout << (par1 == par2? "YES" : "NO") << '\n';
}

signed main(){
    fastio;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}