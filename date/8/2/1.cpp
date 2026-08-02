#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll vis[200010];
ll a[200010];
void solve() {
    ll n;
    cin >> n;
    for(ll i = 1; i <= 2 * n; i++) vis[i] = 0, a[i] = 0;
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= n; j++) {
            ll x;
            cin >> x;
            if(vis[x]) continue;
            a[i + j] = x;
            vis[x] = 1;
        }
    }
    for(ll i = 1; i <= 2 * n; i++) {
        if(!vis[i]) a[1] = i;
    }  
    for(ll i = 1; i <= 2 * n; i++) cout << a[i] << ' ';
    cout << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}