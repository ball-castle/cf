#include <bits/stdc++.h>
using namespace std;
using ll = long long;


/*
https://codeforces.com/problemset/problem/1625/B
两个和谐子段的最大长度
某个对应位置相等
在原数组里找到两个相等的元素
那么如果我现在已经有了一段包括其中一个相等元素的子段
平移距离就行
*/
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];

    map<ll, ll> la;
    ll mi = 4e18;
    for(ll i = 0; i < n; i++) {
        if(la.count(a[i])) mi = min(mi, i - la[a[i]]);
        la[a[i]] = i;
    }
    if(mi == 4e18) {cout << -1 << '\n'; return;}
    cout << n - mi << '\n';
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}