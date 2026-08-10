#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
这种显然就是计数问题
不用输出过程
所以直接计算就行
map 遍历式 nlogn的
最后只会剩下最多个数的那个用不完，那么它可以用多少呢
是不是 mx - left - 2;

*/
ll ct[200010];


void solve() {
    ll n;
    cin >> n;

    map<ll, ll> cnt;
    ll sum = 0;

    for(ll i = 0; i < n; i++) {
        ll x;
        cin >> x;

        sum += x;
        cnt[x]++;
    }

    ll mx = 0;
    ll v = 0;

    for(auto [x, c] : cnt) { // 遍历map的经典手段
        if(c > mx) {
            mx = c;
            v = x;
        }
    }
    ll left = n - mx;
    ll use = left + 2;

    if(mx > use) {
        ll m = mx - use;
        sum -= m * v;
    }
    cout << sum << '\n';

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    cin >> T;
    while(T--) solve();
}