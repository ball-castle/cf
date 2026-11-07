#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    ll x, y, z;

    
    cin >> n >> m >> x >> y >> z;
    vector<ll> a(n + 1), b(m + 1);

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];

    vector<ll> dp(n + 1, 4e18), ndp(n + 1, 4e18);

    for(int i = 1; i <= n; i++) {
        dp[i] = x + (i - 1) * z + abs(a[i] - b[i]) * y;
    }
    for(int j = 2; j <= m; j++) {
        ll bc = 4e18;
        for(int k = 1; k <= n; k++) {
            bc = min(bc, dp[k] + (n - k) * z);
        }

    ll bs = 4e18;
    for(int i = 1; i <= n; i++) {
        ndp[i] = min(bs, bc + x) + (i - 1) * z 
                +(i - 1) * z;
                + abs(a[i] - b[j]) * y;
        bs = min(bs, dp[i] - i * z);
    }
    dp.swap(ndp);
    }
    ll ans = 4e18;
    for(int i = 1; i <= n; i++) {
        ans = min(ans, dp[i] + (n - i) * z);
    }

    cout << ans << '\n';
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    while(T--) solve();
    return 0;
}