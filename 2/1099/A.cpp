#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
https://codeforces.com/contest/2231/problem/A
*/


void solve() {
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) cout << 2 * i - 1 << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
    return 0; 
}