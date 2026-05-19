#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
https://codeforces.com/contest/2230/submit
*/
void solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = n * a;
    
    ans = min(ans, min((n / 3 + 1) * b, n / 3 * b + n % 3 * a));
    cout << ans << '\n';
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}