#include <bits/stdc++.h>
using namespace std;

using ll = long long;

inline ll read() {
    ll x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
    return x * f;
}


/*

*/

ll a[100010];
void solve() {
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1, [&](ll x, ll y) {
        return x < y;
    });
    ll ans = 0;
    for(ll i = 1; i <= n; i++) ans += a[i];
    if(ans % 2 != 0) {cout << ans << '\n'; return;}
    for(ll i = 1; i <= n; i++) if(a[i] % 2 == 1) {ans -= a[i]; break;}
    if(ans % 2 == 0) {cout << 0 << '\n'; return;}
    cout << ans << '\n';

}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T = 1;
    // cin >> T;

    while(T--) {
        solve();
    }
    
    return 0;
}
