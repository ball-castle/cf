#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
想像过程

不变量
p + q是不变的
取最大的 n
dx * dx + dy * dy 最小


*/


void solve() {
    ll x, y;
    cin >> x >> y;

    ll S = x + y;

    ll n = 0;
    while((n + 1) * (n + 2) / 2 <= S) n++;

    ll T = n * (n + 1) / 2;
    ll D = S - T;  // D = dx + dy

    ll L = max(0ll, D - y);
    ll R = min(x, D);     // dx的限制范围

    ll dx = D / 2;
    dx = max(dx, L);
    dx = min(dx, R);
    
    ll p = x - dx;  // 现在问题划归为 用我们的字符串凑出这个数字

    string ans;

    for(ll i = 1; i <= n; i++) {
        ll w = n - i + 1;    // 前面加的1的价值会更高 刻画某一轮加的1的价值

        if(w <= p) {
            ans += 'X';
            p -= w;
        }
        else {
            ans += 'Y';
        }
    }

    cout << ans << '\n';

}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    cin >> T;
    while(T--) solve();
}
