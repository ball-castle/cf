#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int mr[6010][6010]; // mr[len][mn]：长度为 len，值域起点为 mn 的 good 子段最小右端点
int ml[6010][6010]; // ml[len][mn]：长度为 len，值域起点为 mn 的 good 子段最大左端点
ll vis[6010];
ll a[6010];

void solve() {
    ll n;
    cin >> n;

    for(ll i = 1; i <= n; i++) cin >> a[i];

    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= n; j++) {
            mr[i][j] = 4e18;
            ml[i][j] = 0;
        }
    }

    for(ll i = 1; i <= n; i++) vis[i] = 0;

    ll t = 0;

    for(ll l = 1; l <= n; l++) {
        t++;
        ll mn = n + 1, mx = 0;

        for(ll r = l; r <= n; r++) {
            if(vis[a[r]] == t) break;
            vis[a[r]] = t;

            mn = min(mn, a[r]);
            mx = max(mx, a[r]);

            ll len = r - l + 1;

            if(mx - mn + 1 == len) {
                mr[len][mn] = min(mr[len][mn], (int)r);
                ml[len][mn] = max(ml[len][mn], (int)l);
            }
        }
    }

    ll ans = 0;

    for(ll l = 1; l <= n; l++) {
        t++;
        ll mn = n + 1, mx = 0;

        for(ll r = l; r <= n; r++) {
            if(vis[a[r]] == t) break;
            vis[a[r]] = t;

            mn = min(mn, a[r]);
            mx = max(mx, a[r]);

            ll len = r - l + 1;

            if(mx - mn + 1 == len) {
                ll nxt = mn + len;
                if(nxt <= n) {
                    if(mr[len][nxt] < l || ml[len][nxt] > r) {
                        ans = max(ans, len);
                    }
                }

                ll pre = mn - len;
                if(pre >= 1) {
                    if(mr[len][pre] < l || ml[len][pre] > r) {
                        ans = max(ans, len);
                    }
                }
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;

    while(T--) {
        solve();
    }

    return 0;
}