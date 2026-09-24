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

    auto search = [&](int x) -> int{
        int l=0, r=sz(arr[x])-1;
        while (l<r){
            int m = l+(r-l)/2;
            vector<int> tmp = ans;
            for (int i=l; i<=m; i++) tmp.push_back(arr[x][i]);
            if (query(tmp, ans.back())) r = m;
            else l = m+1;
        }
        return arr[x][l];
    };

    for (int x=mx-1; x>=0; x--){
        ans.push_back(search(x));
    }

    cout << "! " << sz(ans) << ' ';
    for (auto a: ans) cout << a << ' ';
    cout << endl;
}

signed main(){
    fastio;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}