#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
考虑起来不难
1 3 可以变成两个2
最后答案的情况 最少能到多少
！！！操作次数越多价值越高
被划掉的数越少 只有超出的范围可以产生价值
*/
ll a[100010];
ll ct[10], m[10];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    
    ll mi = 4e18, mx = -4e18;
    for(ll i = 1; i <= n; i++) cin >> a[i], mi = min(mi, a[i]), mx = max(mx, a[i]);

    ll ans = 0;
    if(mx - mi <= 1) {
        cout << n << '\n';
        for(ll i = 1; i <= n; i++) cout << a[i] << ' ';
        cout << '\n';
        return 0;
    }
    for(ll i = 1; i <= n; i++) {
        if(a[i] == mi) ct[1]++;
        else if(a[i] == mx) ct[3]++;
        else ct[2]++;
    }

    
    if(min(ct[1], ct[3]) < ct[2] / 2) {
        m[1] = ct[1] + ct[2] / 2;
        m[3] = ct[3] + ct[2] / 2;
        m[2] = ct[2] % 2;
    }

    else {
        m[1] = ct[1] - min(ct[1], ct[3]);
        m[2] = ct[2] + 2 * min(ct[1], ct[3]);
        m[3] = ct[3] - min(ct[1], ct[3]);
    }

    for(ll i = 1; i <= 3; i++) ans += min(m[i], ct[i]);
    cout << ans << '\n';

    for(ll i = 1; i <= m[1]; i++) cout << mi << ' ';
    for(ll i = 1; i <= m[2]; i++) cout << mi + 1 << ' ';
    for(ll i = 1; i <= m[3]; i++) cout << mx << ' ';
    
    return 0;
}