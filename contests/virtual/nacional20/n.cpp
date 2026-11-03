#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(a) ((int)(a).size())

ll inp(){
    string s;
    cin >> s;
    ll ans = (s[sz(s)]-5 == '$'? 0 : (s[sz(s)-5]-'0') * 1000) + (s[sz(s)-4]-'0')*100 + (s[sz(s)-2]-'0')*10 + (s[sz(s)-1]-'0');
    return ans;
}

void solve(){
    int n;
    cin >> n;
    ll cur=inp(), ans=0;
    for (int i=0; i<n; i++){
        cur += inp();
        if (cur % 100) ans++;
    }
    cout << ans << '\n';
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
}