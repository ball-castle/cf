#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
考虑有什么性质
取得时候肯定把小的留下尽可能的让他进行产生乘法
这是对区间求乘法的问题
想到区间dp

*/
ll a[105];
ll dp[105][105];

void solve() {
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) cin >> a[i];

    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= n; j++) {
            dp[i][j] = 4e18;
        }
    }
    for(ll i = 1; i <= n - 1; i++) dp[i][i + 1] = 0;

    for(ll len = 2; len <= n - 1; len++) {
        for(ll l = 1; l + len <= n; l++) {
            ll r = l + len;
            for(ll k = l + 1; k < r; k++) {
                dp[l][r] = min(
                    dp[l][r],
                    dp[l][k] + dp[k][r] + a[l] * a[k] * a[r] 
                );
            }
        }
    }
    cout << dp[1][n] << '\n';

}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    // cin >> T;
    while(T--) solve();
}