#include <bits/stdc++.h>
using namespace std;
using ll = long long;


/*
对于每个新的坐标的时候更新答案
前面维护最大前缀和  最小前缀和就行
更新路径

*/


void solve() {
    ll n;
    cin >> n;

    ll a;
    cin >> a;

    ll lo = a, hi = a, ans = a;
    for(int i = 2; i <= n; i++) {
        cin >> a;

        ans = max(ans,  a + max(abs(lo), abs(hi)));

        lo = a + 2 * min(0ll, lo);
        hi = a + 2 * max(0ll, hi);
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