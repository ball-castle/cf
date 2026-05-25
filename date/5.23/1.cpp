#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {
    ll x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    ll ans = abs(x2 - x1) + abs(y2 - y1);
    if(x1 == x2 && x2 == x3 && y3 > min(y1, y2) && y3 < max(y1, y2)) ans += 2;
    if(y1 == y2 && y2 == y3 && x3 > min(x1, x2) && x3 < max(x1, x2)) ans += 2;

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