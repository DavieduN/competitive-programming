// https://codeforces.com/problemset/problem/2033/E

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
    vector<int> arr (n+1), used (n+1);
    for (int i=0; i<n; i++){
        cin >> arr[i+1];
    }
    int ans=0;
    for (int i=1, cur=0; i<=n; i++){
        if (used[arr[i]]) continue;
        int x = arr[i];
        used[x] = 1;
        cur = 1;
        while (arr[x] != arr[i]){
            x = arr[x];
            cur++;
            used[x] = 1;
        }
        ans += (cur-1)/2;
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