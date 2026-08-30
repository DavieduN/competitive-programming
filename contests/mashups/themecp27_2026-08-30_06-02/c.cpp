// https://codeforces.com/problemset/problem/1876/B

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

const int M = 998244353;
const int M2 = 499122177;

vector<int> divisors(int a){
    vector<int> ans;
    for (int i=1; i*i<=a; i++){
        if (a%i) continue;
        ans.push_back(i);
        if (i*i != a) ans.push_back(a/i);
    }
    return ans;
}

void solution(){
    int n;
    cin >> n;
    vector<int> arr (n), used (n);
    ll y=1;
    for (int i=0; i<n; i++){
        cin >> arr[i];
        y = y*2%M;
    }
    vector<pair<int, int>> vals;
    for (int i=0; i<n; i++) vals.push_back({arr[i], i});
    sort(rall(vals));
    ll ans=0;
    for (auto [a, i]: vals){
        vector<int> div = divisors(i+1);
        ll x = 1;
        for (auto d: div) if (!used[d-1]) {
            used[d-1] = 1;
            y = y*M2%M;
            x = x*2%M;
        }
        dbg(a, i, x-1, y);
        ans = (ans + ((ll)a * ((x-1+M)%M * y % M))%M)%M;
    }
    cout << ans << '\n';
}

signed main(){
    fastio;
    int cases=1;
    //cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}