// https://codeforces.com/problemset/problem/1844/D

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

vector<int> get_div(int x){
    vector<int> ans;
    for (int i=1; i*i<=x; i++){
        if (x%i) continue;
        ans.push_back(i);
        if (i*i != x) ans.push_back(x/i);
    }
    sort(all(ans));
    return ans;
}

void solution(){
    int n;
    cin >> n;
    vector<int> divs = get_div(n);
    vector<int> ans (n, 1), vis (n);
    queue<pair<int, int>> q;
    for (int i=0; i<n; i++) q.push({1, i});
    while (!q.empty()){
        auto [x, u] = q.front(); q.pop();
        if (ans[u] > x || vis[u]) continue;
        vis[u] = 1;
        for (auto d: divs){
            int v = u+d;
            if (v >= n) break;
            if (ans[v] == ans[u]){
                ans[v] = ans[u]+1;
                q.push({ans[v], v});
            }
        }
        for (auto d: divs){
            int v = u-d;
            if (v < 0) break;
            if (ans[v] == ans[u]){
                ans[v] = ans[u]+1;
                q.push({ans[v], v});
            }
        }
    }
    for (int i=0; i<n; i++){
        char c = 'a'+ans[i]-1;
        cout << c;
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