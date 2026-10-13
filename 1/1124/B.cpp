#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*

性质1  （找规律)
我们可以对原数字继续xor 3 6 9 12
发现这些数字二进制 都是偶数个1 
所以popcount 奇偶性不变
奇数肯定不行
偶数的可能可以
0 3 5 6 9 10 12 15
性质2
我们并不是仅限于相邻两个
我们可以对于中间都操作x 实现头尾x 任意


最后只要是偶数我们都可以操作 全部变成0 处理最后一个就行

*/
bool good(int x) {
    return __builtin_popcount(x) % 2 == 0;
}


void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n + 1);

    ll ans = 0;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(good(a[i])) ans++;
    }

    cout << ans << '\n';

    while(q--) {
        ll p, x;
        cin >> p >> x;
        if(good(a[p])) {
            ans--;
        }
        a[p] = x;
        if(good(a[p])) {
            ans++;
        }
        cout << ans << ' ';
    }
    cout << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}