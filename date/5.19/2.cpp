#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
https://codeforces.com/problemset/problem/2194/A
这题得想象一下结果的画面
w - 1空着然后有一个
*/
void solve() {
    ll n, w;
    cin >> n >> w;
    ll ans = 0;
    ans = n / w;
    ans = n - ans;
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