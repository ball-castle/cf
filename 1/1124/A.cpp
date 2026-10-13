#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
在这道题我们并没有去模拟删除操作
而是通过模拟去找到了性质 想象出谁到底被删除了 然后怎么删除的
最终我们直接将需要的加到答案里就行
*/




void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n + 1);
    for(ll i = 1; i <= n; i++) cin >> a[i];

    ll ans = 0;

    if(2 * k <= n) {
        for(int i = k; i <= n - k + 1; i++) ans += a[i];
        for(int i = 1; i < k; i++) ans += max(a[i], a[n - i + 1]);
        cout << ans << '\n';
        return;
    }
    for(int i = 1; i <= n - k + 1; i++) {
        ans += max(a[i], a[n - i + 1]);
    }
    cout << ans << '\n';
    
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    ll T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}