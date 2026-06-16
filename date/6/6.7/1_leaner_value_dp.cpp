#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll a[1000010];
ll dp[1000010]; // 值dp 以前是对末尾进行max转移 变成特定属性转移



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    ll ans = 0;
    for(ll i = 1; i <= n; i++) cin >> a[i], dp[a[i]] = 1;
    for(ll i = 1; i <= 1e6; i++) {
        if(dp[i] == 0) continue;

        ans = max(dp[i], ans);

        for(ll j = 2 * i; j <= 1000000; j += i) if(dp[j] > 0) dp[j] = max(dp[j], dp[i] + 1);
    }    
    cout << ans << '\n';
    return 0;
}