#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {
    ll n, x1, x2, k;
    cin >> n >> x1 >> x2 >> k;

    
    if(n <= 3) {
        cout << 1 << '\n';
        return;
    }

    ll m = abs(x1 - x2);
    ll d = min(m, n - m);

    cout << d + k << '\n';
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}