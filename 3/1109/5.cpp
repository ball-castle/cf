#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll pre[200010];
// 1 -> i 的不和谐数量 


void solve() {
    ll n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = ' ' + s;

    for(ll i = 2; i <= n; i++) {
        pre[i] = pre[i - 1] + (s[i] == s[i - 1]);
    }
    while(q--) {
        ll l, r, k;
        cin >> l >> r >> k;
        ll sum = pre[r] - pre[l];
        cout << ((sum > k * 2) ? "NO" : "YES") << '\n';
    }

}

/*
2
5 5
00110
1 5 1
1 5 2
2 4 1
1 2 0
3 4 0
4 2
1010
1 4 0
2 3 1
YES
NO
NO
YES
YES
NO
NO

*/


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}