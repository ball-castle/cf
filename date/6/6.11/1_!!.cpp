#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll a[200010], ans[200010];

struct node {
    ll ct;
    ll id;
};

node m[200010];

void solve() {
    ll n;
    cin >> n;

    for(ll i = 1; i <= n; i++) {
        cin >> a[i];
        ans[i] = 1;
    }

    ll cnt = 0;

    for(ll i = 2; i <= n; i++) {
        ll need = max(a[i - 1] - a[i], 0ll);
        if(need > 0) {
            cnt++;
            m[cnt].ct = need;
            m[cnt].id = i;
        }
    }

    sort(m + 1, m + cnt + 1, [&](node x, node y) {
        return x.ct > y.ct;
    });

    ll now = n;

    for(ll i = 1; i <= cnt; i++) {
        ans[now] = m[i].id;
        now--;
    }

    for(ll i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}