#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
https://codeforces.com/problemset/problem/1891/C
*/

void solve() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll i = 0, j = n - 1;
    ll sum = 0, ans = 0;
    while(i <= j) {
        
        if(i == j) {
            ll t = sum + a[i];
            if(t <= 1) {ans += a[i]; break;}
            ans += (t / 2) + 1 + (t % 2) - sum;
            break;
        }
        if(sum + a[i]> a[j]) a[i] -= (a[j] - sum), ans += a[j] - sum + 1, j--, sum = 0;
        else if(sum + a[i] == a[j]) ans += a[i] + 1, i++, j--, sum = 0;
        else ans += a[i], sum += a[i], i++;
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