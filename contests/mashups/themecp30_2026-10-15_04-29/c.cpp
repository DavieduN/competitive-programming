// https://codeforces.com/problemset/problem/2155/C

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

bool check(vector<int>& a, vector<int>& b){
    int n = sz(a);
    vector<int> l (n), r (n);
    for (int i=0; i<n; i++) l[i] = (i? l[i-1] : 0) + (b[i] == 0);
    for (int i=n-1; i>=0; i--) r[i] = (i+1<n? r[i+1] : 0) + (b[i] == 1);
    for (int i=0; i<n; i++){
        if (a[i] != 1 + (i? l[i-1] : 0) + (i+1<n? r[i+1] : 0)) return false;
    }
    return true;
}

int test(vector<int>& a, int guess){
    int n = sz(a);
    vector<int> b (n);
    b[0] = guess;
    for (int i=0; i+1<n; i++){
        int x = a[i+1]-a[i];
        if (b[i]){
            if (x == 0) b[i+1] = 0;
            else if (x == -1) b[i+1] = 1;
            else return 0;
        }
        else{
            if (x == 0) b[i+1] = 1;
            else if (x == 1) b[i+1] = 0;
            else return 0;
        }
    }

    return check(a, b);
}

void solution(){
    int n;
    cin >> n;
    vector<int> a (n);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    cout << test(a, 0) + test(a, 1) << '\n';
}

signed main(){
    fastio;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}