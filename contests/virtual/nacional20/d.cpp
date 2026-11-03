#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(a) ((int)(a).size())


void solve(){
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<>> q;
    for (int i=0, x; i<n; i++){
        cin >> x;
        q.push(x);
    }
    if (n == 1){
        cout << "N\n";
        return;
    }
    int fst=-1;
    while (sz(q) >= 2){
        int a = q.top(); q.pop();
        int b = q.top(); q.pop();
        if (a == b) q.push(a+1);
        else{
            fst = a;
            q.push(b);
            break;
        }
    }
    while (sz(q) >= 2){
        int a = q.top(); q.pop();
        int b = q.top(); q.pop();
        if (a == b) q.push(a+1);
        else{
            q.push(a);
            q.push(b);
            break;
        }
    }
    cout << (sz(q) == 1? "Y" : "N") << '\n';
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
}