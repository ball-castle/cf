#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
初步想法
贪心时间做题数多使得总分高
但是做题数多会导致其中有些题目不算数
做题数最终会等于分数（不算数的题只有负作用）

选出 x 题，让它们都得分，时间不超
也就是选 x 道满足 a_i >= x 的题，并且总时间 <= T
关键在于k是取得题数，正向不好想，会打架
所以反向验证

二分答案的思路
如果 x 可行，那么比 x 更小的值一定可行
所以可以二分最大可行的 x
*/

struct node {
    ll a;
    ll id;
    ll t;
};


ll n, T;
node p[200010];

bool check(ll x) {
    ll cnt = 0;
    ll sum = 0;
    for(ll i = 1; i <= n; i++) {
        if(p[i].a >= x) {
            cnt++;
            sum += p[i].t;
            if(cnt == x) return sum <= T;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> T;

    for (ll i = 1; i <= n; i++) {
        p[i].id = i;
        cin >> p[i].a >> p[i].t;
    }

    sort(p + 1, p + n + 1, [&](node &x, node &y) {
        return x.t < y.t;
    });

    ll l = 1, r = n;
    ll ans = 0;

    while(l <= r) {
        ll mid = l + (r - l) / 2;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        } 
        else {
            r = mid - 1;
        }
    }

    vector<ll> w;

    for(ll i = 1; i <= n; i++) {
        if((ll)w.size() < ans && p[i].a >= ans) w.push_back(p[i].id);
    }

    cout << ans << '\n';
    cout << w.size() << '\n';

    for(ll id : w) cout << id << ' ';

    cout << '\n';

    return 0;
}