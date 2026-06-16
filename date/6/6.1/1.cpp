#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    ll ans = 0;
    x++, y++;
    ans = max(ans, (x - 1) * b);
    ans = max(ans, (a - x) * b);
    ans = max(ans, a * (y - 1));
    ans = max(ans, a * (b - y));

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