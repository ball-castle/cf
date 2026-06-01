#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
https://codeforces.com/problemset/problem/1490/A
唯一的知识点在于向上取整
(a + b - 1)  / b;
*/


void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    ll ans = 0;
    for(int i = 1; i < n; i++) {
        ll mx = max(a[i], a[i - 1]), mi = min(a[i], a[i - 1]);
        ll m = (mx + mi - 1) / mi;
        while(m > 2) m = (m + 1) / 2, ans++;  
    }
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