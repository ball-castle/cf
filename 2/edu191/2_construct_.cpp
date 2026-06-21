#include <bits/stdc++.h>
using namespace std;

using ll = long long;


/*
构造的基本思路都是由简单的量构成
如果不行，做简单修改


*/
void solve() {
    ll n;
    cin >> n;

    for(ll i = 1; i <= n; i++) {
        cout << i << ' ';
    }

    for(ll i = n; i >= 1; i--) {
        cout << i << ' ';
    }

    for(ll i = 1; i <= n; i++) {
        cout << i % n + 1 << ' ';
    }

    for(ll i = n; i >= 1; i--) {
        cout << i % n + 1 << ' ';
    }

    cout << '\n';
}   




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T = 1;
    cin >> T;
    
    while(T--) {
        solve();
    }
    
    return 0;
}
