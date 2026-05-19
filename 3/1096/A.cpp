#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
https://codeforces.com/contest/2227
*/
void solve() {
    ll a, b;
    cin >> a >> b;
    if(a % 2 == 1 && b % 2 == 1) {cout << "NO" << '\n'; return;}
    cout << "YES" << '\n';
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}