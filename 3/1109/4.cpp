#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a[200010], b[200010];
ll pre[200010];

void solve() {
    ll n, m;
    cin >> n >> m;
    for(ll i = 1; i <= n; i++) cin >> a[i];
    for(ll i = 1; i <= m; i++) cin >> b[i];
    sort(b + 1, b + m + 1);
    // b[i - 1], b[i]
    for(ll i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    ll ans = 0;
    for(ll i = 1; i <= m; i++) {
        ll sum = 0;
        sum = pre[b[i]] - pre[b[i - 1]];
        ans += abs(sum);
    }
    ans += pre[n] - pre[b[m]]; 
    cout << ans << '\n';
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}