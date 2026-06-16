#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct node {
    ll f, ok; // ok = 1 表示 c > 0
};

vector<node> v;

void solve() {
    ll n, d, S;
    cin >> n >> d >> S;

    ll P = 0;       
    ll Z = 0;       
    ll extra = 0;   

    ll mn = 4e18;    

    for(ll i = 1; i <= n; i++) {
        ll c, f, l;
        cin >> c >> f >> l;
        if(c > 0) {
            P++;
            extra += c - 1;
        } 
        else {
            Z++;
        }

        if(l >= d) {
            v.push_back({f, c > 0});
            if(c > 0) mn = min(mn, f);
        }
    }

    sort(v.begin(), v.end(), [](node x, node y) {
        return x.f < y.f;
    });

    ll m = v.size();

    vector<ll> pre(m + 1, 0); // 前 i 个燃料和
    vector<ll> ct(m + 1, 0);  // 前 i 个里面 c > 0 的数量

    for(ll i = 1; i <= m; i++) {
        pre[i] = pre[i - 1] + v[i - 1].f;
        ct[i] = ct[i - 1] + v[i - 1].ok;
    }

    ll ans = 0;
    ll cost = 0;

    auto update = [&](ll num, ll fuel) {
        if(fuel > S) return;
        if(num > ans) {
            ans = num;
            cost = fuel;
        } 
        else if(num == ans && fuel < cost) {
            cost = fuel;
        }
    };

    for(ll k = 1; k <= m; k++) {
        update(k, pre[k]);

        if(mn != 4e18) {
            ll now;

            if(ct[k] > 0) {
                now = pre[k];
            } 
            else {
                now = pre[k] - v[k - 1].f + mn;
            }

            ll num = P + min(Z, extra + k);
            update(num, now);
        }
    }
    cout << ans << ' ' << cost << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}