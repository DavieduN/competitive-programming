// https://codeforces.com/problemset/problem/1914/E1

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
    vector<int> a (n), b (n), used (n);
    for (auto& x: a) cin >> x;
    for (auto& x: b) cin >> x;
    vector<pair<ll, int>> bestA, bestB;
    for (int i=0; i<n; i++){
        bestA.push_back({a[i]-1+b[i], i});
        bestB.push_back({b[i]-1+a[i], i});
    }
    sort(all(bestA));
    sort(all(bestB));
    ll ans=0;
    for (int i=0; i<n; i++){
        while (used[bestA.back().second]) bestA.pop_back();
        while (used[bestB.back().second]) bestB.pop_back();
        if (i&1){
            ans -= b[bestB.back().second]-1;
            used[bestB.back().second] = 1;
        }
        else{
            ans += a[bestA.back().second]-1;
            used[bestA.back().second] = 1;
        }
    }
    cout << ans << '\n';
}

signed main(){
    fastio;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}