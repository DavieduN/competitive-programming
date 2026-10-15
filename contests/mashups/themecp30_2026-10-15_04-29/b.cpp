// https://codeforces.com/problemset/problem/1931/E

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
    int n, m;
    cin >> n >> m;
    int ans=0;
    vector<int> arr (n);
    for (int i=0; i<n; i++){
        string s;
        cin >> s;
        while (s.back() == '0'){
            arr[i]++;
            s.pop_back();
        }
        ans += s.size();
    }
    sort(rall(arr));
    for (int i=1; i<n; i+=2) ans += arr[i];
    cout << (ans > m? "Sasha" : "Anna") << '\n'; 
}

signed main(){
    fastio;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}