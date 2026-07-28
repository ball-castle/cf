#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
路径的本质其实是点的排列
考虑排列的个数就行 组合问题
*/

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

void solve() {
    ll n;
    cin >> n;

    ll sum = 0;
    vector<ll> a(n);
    for(ll &x : a) cin >> x, sum += x;

    sort(a.begin(), a.end());

    ll sum2 = 0;
    for(ll i = 0; i < n; i++) {
        sum2 += a[i] * (2 * i - n + 1);
    }

    ll up = sum + 2 * sum2;
    ll down = n;

    ll g = gcd(up, down);
    cout << up / g << ' ' << down / g << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}