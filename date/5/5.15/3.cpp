#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
题目一开始考虑暴力
但是一开始是不好暴力的
由于异或是有结合率的
所以当于两个连续区间，左边异或大于右边疑惑
这样可以直接对所有区间枚举o(n ^ 3)

再想，现在需要右边异或变小
就是需要最高位相同，如果这三个最高位都相同，直接结束
10 ^ 9 < 2 * 30 只要有61个数就是直接结束

*/

ll a[100010];


ll ca(ll l, ll r) {
    ll ans = a[l];
    
    for(ll i = l + 1; i <= r; i++) ans ^= a[i];
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) cin >> a[i];

    if(n > 60) {cout << 1 << '\n'; return 0;}
    ll ans = 4e18;
    ll f = 0;
    for(ll l = 1; l <= n; l++) {
        for(ll r = l; r <= n; r++) {
            for(ll m = l + 1; m <= r; m++) {
                if(ca(l, m - 1) > ca(m, r)) ans = min(ans, r - l - 1), f = 1;
            }
        }
    }
    if(!f) {cout << -1 << '\n'; return 0;}
    cout << ans << '\n';
    return 0;
}