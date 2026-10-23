#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
从两个我们去操作一下
最大可以变多少 其实看的是max
取的是或  所以其实很简单

*/
void solve() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];


    ll mx = 0, mn = 4e18;
    for(int i = 0; i < n; i++) {
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }

    ll d = mx ^ mn;

    ll mask = 0;

    while(d) {
        mask = (mask << 1) | 1;
        d >>= 1;
    }
    cout << (mx | mask) << '\n';

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    ll T = 1;
    cin >> T;
    while(T--) solve();
    return 0;

}