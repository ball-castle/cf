#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[200010], a[200010];
/*
转化题目
从结论出发
把这个切成若干段，每段都是相等的值，每段价值最小是多少
每段考虑中位数
并且只用考虑 2 和 3
如果是一个线性数组就好处理了 线性dp 分类
但是环的话就枚举包含1的情况 特殊处理加线性dp
*/
// n, 1; 1, 2; n, 1, 2; n - 1, n, 1; 1, 2, 3

ll c2(ll l, ll r) {
    return abs(a[r] - a[l]);
}

ll c3(ll i, ll j, ll k) {
    return max(a[i], max(a[j], a[k])) - min(a[i], min(a[j], a[k]));
}


ll d(ll l, ll r) {
    ll len = r - l + 1;
    for(int i = 1; i <= len; i++) dp[i] = 4e18;
    dp[0] = 0;
    
    for(int i = 1; i <= len; i++) {
        ll p = l + i - 1;
        if(i >= 2) dp[i] = min(dp[i], dp[i - 2] + c2(p - 1, p));
        if(i >= 3) dp[i] = min(dp[i], dp[i - 3] + c3(p - 2, p - 1, p));
    }
    return dp[len]; 
}

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        dp[i] = 0;
        cin >> a[i];
    }

    ll ans = 4e18;
    ans = min(ans, c2(n, 1) + d(2, n - 1));
    ans = min(ans, c2(1, 2) + d(3, n));
    ans = min(ans, c3(1, 2, 3) + d(4, n));
    ans = min(ans, c3(n, 1, 2) + d(3, n - 1));
    ans = min(ans, c3(n - 1, n, 1) + d(2, n - 2));

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