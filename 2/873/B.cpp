#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}


int a[100010];
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    int ans = 0;
    for(int i = 1; i <= n; i++) ans = gcd(ans, abs(a[i] - i));

    cout << ans << '\n';
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}