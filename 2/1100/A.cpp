#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
过程 or 结果
这题的结果并不是结果的模态，而是结果的值
先求出最小值，然后证明可以达到
求出最小值的过程是每次最大产生2的价值
【mx - mi] / 2

*/



ll a[1010];
void solve() {
    ll n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    ll ans = 0;
    
    ans = (a[n] - a[1] + 1) / 2;
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