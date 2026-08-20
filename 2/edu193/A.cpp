#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;
    ll a = n + 1;
    ll f = 1;
    for(ll i = 2; i * i <= a; i++) {
        if(a % i == 0) f = 0;
    }
    cout << (f ? "YES" : "NO") << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    cin >> T;
    while(T--) solve();
}