#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
https://codeforces.com/problemset/problem/1806/C
这题其实有个比较好的思想，就是交换一下会怎么样，小范围考虑
x1 -> x2 其它不变相减 数学题 假设存在一个不相等 两个括号

想清楚
便利找就行 min
一开始没想明白写的就烂
*/

ll a[400010];

void solve() {
    ll n;
    cin >> n;
    for(ll i = 1; i <= 2 * n; i++) cin >> a[i];
    ll ans = 0, ans1 = 0;
    if(n == 1) {
        ans = abs(a[1] - a[2]);
        cout << ans << '\n';
        return;
    }
    if(n == 2) {
        for(ll i = 1; i <= 2 * n; i++) ans1 += abs(a[i] - 2);
    }
    if(n % 2 != 0) {
        for(ll i = 1; i <= 2 * n; i++) ans += abs(a[i]);
        cout << ans << '\n';
        return;
    }
    for(ll i = 1; i <= 2 * n; i++) ans += abs(a[i] + 1);
    ll mi = 4e18;
    for(ll i = 1; i <= 2 * n; i++) mi = min(mi, ans - abs(a[i] + 1) + abs(a[i] - n));
    ans = 0;
    for(ll i = 1; i <= 2 * n; i++) ans += abs(a[i]);
    ans = min(ans, mi);
    if(n == 2) ans = min(ans, ans1);
    cout << ans << '\n';
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}