#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
依旧从结论出发
中位数的变化 考虑过程
加上两个数 中位数怎么变
如果目标值是 x -> y
1 5 7        9    11 最多移动一位
因为是纯让我们自己构造
如果前面的中位数出现在接下来的移动中间 就不可能
其它都可以通过调数字可能

转化为 以前出现过的数字会不会夹在新的两数之间
自动排序 + 查找 -> set

*/

ll b[200010];

void solve() {
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) cin >> b[i];
    
    ll f = 0;
    set<ll> s;
    s.insert(b[1]);

    for(int i = 2; i <= n; i++) {
        ll mi = min(b[i - 1], b[i]);
        ll mx = max(b[i - 1], b[i]);

        auto it = s.upper_bound(mi);
        if(it != s.end() && *it < mx) f = 1;

        s.insert(b[i]);
    }
    cout << (f ? "NO" : "YES") << '\n';
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}