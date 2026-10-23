#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a[1000010];



/*
对于这种构造 肯定是特殊到一般
肯定跟n / 2有关 就处理一个向上取整还是向下取整

*/
void solve() {
    ll n, m;
    cin >> n >> m;

    if(n == 1) {
        cout << 0 << '\n';
        return;
    }

    ll k = (n + 1) / 2;
    cout << k << '\n';

    for(ll i = 1; i <= k; i++) {
        cout << i << ' ' << i + k - 1 << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    ll T = 1;
    cin >> T;
    while(T--) solve();
    return 0;

}