// https://codeforces.com/problemset/problem/2094/G

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
    int q, m=0;
    cin >> q;

    vector<ll> a;
    int cur=0;
    ll ans[2] = {0, 0};
    ll tot[2] = {0, 0};
    vector<int> bef[2], nxt[2];
    int first[2] = {0, 0}, last[2] = {0, 0};
    
    while (q--){
        int op;
        cin >> op;
        if (op == 1){
            ans[cur] += tot[cur] - m * a[last[cur]];
            first[cur] = last[cur];
            last[cur] = bef[cur][last[cur]];

            ans[!cur] += m * a[first[!cur]] - tot[!cur];
            last[!cur] = first[!cur];
            first[!cur] = nxt[!cur][first[!cur]];
        }
        else if (op == 3){
            ll k;
            cin >> k;
            a.push_back(k);
            m++;

            
            bef[0].push_back(last[0]); bef[1].push_back(last[1]);
            nxt[0].push_back(first[0]); nxt[1].push_back(first[1]); 

            nxt[0][last[0]] = nxt[1][last[1]] = m-1;
            bef[0][first[0]] = bef[1][first[1]] = m-1;
            
            tot[cur] += k;
            ans[cur] += m*k;
            last[cur] = m-1;

            ans[!cur] += tot[!cur] + k;
            tot[!cur] += k;
            first[!cur] = m-1;
        }
        else cur = !cur;
        cout << ans[cur] << '\n';
    }
}

signed main(){
    fastio;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}