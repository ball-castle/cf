#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// 本质在看我们能凑出什么数 从1往上推发现我们中间所有数都可以得到

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll sum = a * 1 + b * 2 + c * 3;
    cout << sum % 2 << '\n';
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}