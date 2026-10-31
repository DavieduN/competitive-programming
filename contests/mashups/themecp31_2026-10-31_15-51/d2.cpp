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

uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
}

map<ll, uint64_t> h;

void solution(){
    int n;
    cin >> n;

    map<uint64_t, int> mp;
    vector<uint64_t> arr (n);
    for (int i=0, x; i<n; i++){
        cin >> x;

        while (x != 1){
            arr[i] ^= h[fac[x]];
            x /= fac[x];
        }
        
        mp[arr[i]]++;
    }

    ll ans=0;
    uint64_t cur=0;
    for (int i=0; i<n; i++){
        cur ^= arr[i];
        ans += mp[cur];
    }

    cout << ans << '\n';
}

signed main(){
    fastio;
    sieve(MX-1);
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    for (auto p: primes) h[p] = splitmix64(rng());
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}