#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
https://codeforces.com/problemset/problem/2082/B
交换的角度来看 F C  CF 分情况考虑


*/

void solve() {
    ll x, n, m;
    cin >> x >> n >> m; // n 向下

    ll mi = x, mx = x;
    
    ll m1 = m, n1 = n;
    while(m1 > 0 && mi > 1) {
        mi = (mi + 1) / 2;
        m1--;
    }
    while(n1 > 0 && mi > 0) {
        mi = mi / 2;
        n1--;
    }

    ll n2 = n, m2 = m;
    while(n2 > 0 && mx > 0) {
        mx = mx / 2;
        n2--;
    }
    while(m2 > 0 && mx > 1) {
        mx = (mx + 1) / 2;
        m2--;
    }
    cout << mi << ' ' << mx << '\n';
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}