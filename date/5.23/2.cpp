#include <bits/stdc++.h>
using namespace std;
using ll = long long;


/*
https://codeforces.com/problemset/problem/1172/D
先考虑右边，如果右边没有那就会一直走
不用变向
过程 or 结果
核心矛盾在于四个点
考虑过程
第一步应该抽象成 i行进入 r[i]行出
这里的过程到底是什么过程呢，你想当时那个中位数的题目，是考虑加入一个会产生什么样的影响
初始位置是r[i] = i
加入一个传送门(x, y) 会产生什么样的结果
(x, y) (z, w)






*/



ll n;
ll r[1010], c[1010];

ll fro(ll a[], ll x) {
    for(ll i = 1; i <= n; i++) {
        if(a[i] == x) return i;
    }
    return -1;
}

void solve() {
    cin >> n;

    for(ll i = 1; i <= n; i++) cin >> r[i];
    for(ll i = 1; i <= n; i++) cin >> c[i];

    vector<array<ll, 4>> ans;

    for(ll i = 1; i <= n; i++) {
        ll a = fro(r, i);
        ll b = fro(c, i);

        if(a == i && b == i) continue;

        ans.push_back({i, b, a, i});

        r[a] = r[i];
        c[b] = c[i];

        r[i] = i;
        c[i] = i;
    }

    cout << ans.size() << '\n';

    for(auto [x, y, z, w] : ans) {
        cout << x << ' ' << y << ' ' << z << ' ' << w << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}