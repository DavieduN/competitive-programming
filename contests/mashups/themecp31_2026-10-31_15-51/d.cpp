// https://codeforces.com/problemset/problem/2275/F

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

const int MX = 1e6+123;
ll fac[MX];
vector<ll> primes;
void sieve(ll n){
    for (ll i=1; i<n; i++) fac[i] = i;
    for (ll i=2; i<n; i++){
        if (fac[i] == i) primes.push_back(i);
        for (auto p: primes){
            if (i*p >= n) break;
            fac[i*p] = p;
            if (i%p == 0) break;
        }
    }
}


void solution(){
    int n;
    cin >> n;

    map<ll, int> mp;
    vector<vector<int>> arr (n);
    for (int i=0, x; i<n; i++){
        cin >> x;

        vector<int> ctr, fct;
        int lst=-1;
        while (x != 1){
            if (fac[x] != lst){
                lst = fac[x];
                fct.push_back(fac[x]);
                ctr.push_back(0);
            }
            ctr[sz(ctr)-1]++;
            x /= fac[x];
        }
        
        int v=1;
        vector<int> tmp;
        for (int j=0; j<sz(fct); j++) if (ctr[j]%2) tmp.push_back(fct[j]);
        for (auto a: tmp){
            v *= a;
        }
        mp[v]++;
        arr[i] = tmp;
    }

    ll ans=0;
    set<int> cur;
    for (int i=0; i<n; i++){
        for (auto a: arr[i]){
            if (cur.count(a)) cur.erase(a);
            else cur.insert(a);
        }
        if (sz(cur) < 9){
            ll v = 1;
            for (auto a: cur){
                v *= a;
                if (v > 1e6+123) break;
            }
            ans += mp[v];
        }
    }

    cout << ans << '\n';
}

signed main(){
    fastio;
    sieve(MX-1);
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}