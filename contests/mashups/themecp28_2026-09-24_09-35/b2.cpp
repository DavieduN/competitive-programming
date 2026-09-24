// https://codeforces.com/problemset/problem/2133/C

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

int query(vector<int>& nodes, int st){
    cout << "? " << st << ' ' << sz(nodes) << ' ';
    for (auto a: nodes) cout << a << ' ';
    cout << endl;
    int ans;
    cin >> ans;
    return ans;
}

void solution(){
    int n;
    cin >> n;
    vector<int> height (n+1), nodes (n);
    iota(all(nodes), 1);
    vector<vector<int>> arr (n+1);
    int mx=0;
    for (int i=1; i<=n; i++){
        height[i] = query(nodes, i);
        mx = max(height[i], mx);
        arr[height[i]].push_back(i);
    }
    vector<int> ans;
    ans.push_back(arr[mx].back());
    arr[mx].pop_back();
    while (!arr[mx].empty()) arr[mx].pop_back();
    
    for (int x=mx-1; x; x--){
        vector<int> tmp = ans;
        for (int i=1; i<x; i++) for (auto a: arr[i]) tmp.push_back(a);
        for (auto a: arr[x]){
            tmp.push_back(a);
            ans.push_back(a);
            if (query(tmp, ans[0]) == mx) break;
            ans.pop_back();
            tmp.pop_back();
        }
    }

    cout << "! " << sz(ans) << ' ';
    for (auto a: ans) cout << a << ' ';
    cout << endl;
}

signed main(){
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}