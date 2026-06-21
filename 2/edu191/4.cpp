#include <bits/stdc++.h>
using namespace std;

using ll = long long;

/*
核心转化：

合法 <=> 每种数都形成一个连续块
     <=> 总块数 = 不同数个数
     <=> 相邻不同的次数 S = 种类数 - 1

一次交换只影响两个位置附近的边，所以可以局部维护 S。

更关键：
如果一个数 x 能通过一次交换变成连续块，
那么 x 当前的位置形态一定是：
    一个块中缺一个洞 + 外面多一个 x
所以只需要枚举这些“可能修好某个数”的交换。
*/

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    map<ll, vector<int>> pos;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }

    int m = pos.size();

    int S = 0;
    for(int i = 1; i < n; i++) {
        S += (a[i] != a[i - 1]);
    }

    auto good = [&]() {
        return S == m - 1;
    };

    if(good()) {
        cout << "YES\n";
        return;
    }

    // 一次交换最多改变 4 条相邻边
    if(S > m + 3) {
        cout << "NO\n";
        return;
    }

    auto change = [&](int p, ll val) {
        if(p > 0) S -= (a[p] != a[p - 1]);
        if(p + 1 < n) S -= (a[p] != a[p + 1]);

        a[p] = val;

        if(p > 0) S += (a[p] != a[p - 1]);
        if(p + 1 < n) S += (a[p] != a[p + 1]);
    };

    auto get = [&](const vector<int>& v) {
        vector<pair<int, int>> res;
        vector<pair<int, int>> seg;

        int sz = v.size();
        for(int l = 0; l < sz; ) {
            int r = l;
            while(r + 1 < sz && v[r + 1] == v[r] + 1) {
                r++;
            }

            seg.push_back({v[l], v[r]});
            l = r + 1;
        }

        auto add = [&](int x, int y) {
            if(x >= 0 && x < n && y >= 0 && y < n && x != y) {
                res.push_back({x, y});
            }
        };

        if(seg.size() == 2) {
            auto [l1, r1] = seg[0];
            auto [l2, r2] = seg[1];

            // 形如：x ... xxx
            // 把孤立点换到大块旁边
            if(l1 == r1) {
                add(l1, l2 - 1);
                add(l1, r2 + 1);
            }

            // 形如：xxx ... x
            if(l2 == r2) {
                add(l2, l1 - 1);
                add(l2, r1 + 1);
            }

            // 形如：xxx _ xxx
            // 中间只有一个洞
            if(l2 == r1 + 2) {
                int hole = r1 + 1;
                add(l1, hole);
                add(r2, hole);
            }
        }

        if(seg.size() == 3) {
            auto [l1, r1] = seg[0];
            auto [l2, r2] = seg[1];
            auto [l3, r3] = seg[2];

            // 形如：x ... xxx _ xxx
            // 左边孤立点补中间的洞
            if(l1 == r1 && l3 == r2 + 2) {
                add(l1, r2 + 1);
            }

            // 形如：xxx _ xxx ... x
            // 右边孤立点补中间的洞
            if(l3 == r3 && l2 == r1 + 2) {
                add(l3, r1 + 1);
            }
        }

        return res;
    };

    bool ok = false;

    for(auto &[val, v] : pos) {
        auto cand = get(v);

        for(auto [x, y] : cand) {
            ll vx = a[x], vy = a[y];

            change(x, vy);
            change(y, vx);

            if(good()) {
                ok = true;
            }

            change(x, vx);
            change(y, vy);

            if(ok) break;
        }

        if(ok) break;
    }

    cout << (ok ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--) {
        solve();
    }

    return 0;
}