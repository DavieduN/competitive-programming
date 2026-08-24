// $url$

#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double
#define pb push_back

typedef long long C;
typedef complex<C> P;
#define X real()
#define Y imag()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

void read(string file, bool test){
    if (test){
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    }
    else{
        freopen((file+".in").c_str(), "r", stdin);
        freopen((file+".out").c_str(), "w", stdout);
    }
}


void solution(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        
    }
}

signed main(){
    fastio;
    read("name", 1);
    int n=1;
    cin >> n;
    for (int i=0; i<n; i++){
        solution();
    }
}