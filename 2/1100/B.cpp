#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
https://codeforces.com/contest/2229/problem/B
在正式开始写之前应该有个初步的感觉
就是怎么分应该是好的
就是把小的往a扔 大的往b扔
如果不影响最大值那肯定是赚的
那影响最大值呢
最大值本身还是有价值的 a至少也能加到b换过来的东西

结果就是小的往a扔大的往b扔 因为a只有一个最大值有影响

*/




void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    ll mx = -4e18;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    ll mi = -4e18, ans = 0;
    for(int i = 0; i < n; i++) ans += max(a[i], b[i]), mi = max(min(a[i], b[i]), mi);
    ans += mi;
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