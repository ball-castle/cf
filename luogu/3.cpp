#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
肯定是要想到背包
经典的用容量算价值
但是背包放不下 1e8
所以考虑换背包
正常的01背包 里面的是花了这么多钱产生的价值
dp其实有点状态压缩的意思
*/
ll c[100], h[100];
ll dp[100010]; // 获得这么多价值花的钱
void solve() {
    ll m, x;
    cin >> m >> x;
    for(ll i = 1; i <= 100000; i++) dp[i] = 4e18;
    ll v = m * x;
    for(ll i = 1; i <= m; i++) cin >> c[i] >> h[i];
    ll sum = 0;
    for(ll i = 1; i <= m; i++) sum += h[i];

    for(ll i = 1; i <= m; i++) {
        for(ll j = sum; j >= h[i]; j--) {
            if(dp[j - h[i]] != 4e18 && dp[j - h[i]] + c[i] <= (i - 1) * x) {
                dp[j] = min(dp[j], dp[j - h[i]] + c[i]);
            }
        }
    }
    for(ll i = sum; i >= 0; i--) {
        if(dp[i] != 4e18) {
            cout << i << '\n';
            return;
        }
    }
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    cin >> T;
    while(T--) solve();
}