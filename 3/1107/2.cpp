#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
巧妙构造题
利用一些特殊的数字

*/


void solve() {
    ll x;
    cin >> x;
    ll y = 1;

    while(x > 0) {
        x /= 10;
        y *= 10;
    }
    cout << y + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
    return 0; 
}