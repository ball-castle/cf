#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
https://codeforces.com/contest/2038/problem/B
!!!!! 这题的思路在于操作顺序不重要 对于每个位置看次数就行
!然后经典思路先变成0
可以不变成0 如果最大值已经是2了，还没有达到那就是不行 因为这个时候操作不可能再让它达到
然后从合法解可以回退
*/


void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n + 1), ct(n + 1), c(n + 1);
    ll mx = -4e18;
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    while(1) { // 这种循环的写法还蛮好玩的
        mx = -4e18;
        for(int i = 1; i <= n; i++) mx = max(mx, a[i]);
        if(mx < 3) break;
        for(int i = 1; i <= n; i++) {
            c[i] = a[i] / 2;
            ct[i] += c[i];
        }
        for(int i = 1; i <= n; i++) {
            a[i] -= c[i] * 2;
            a[i % n + 1] += c[i];
        }
    }

    for(int i = 2; i <= n; i++) if(a[i] != a[1]) {cout << -1 << '\n'; return;}
    ll mi = 4e18;
    ll ans = 0;
    for(int i = 1; i <= n; i++) mi = min(mi, ct[i]), ans += ct[i];
    cout << ans - mi * n << '\n';
}








int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}