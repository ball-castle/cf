#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;
ll dp[20][4];




void solve() {
    ll l, r;
    cin >> l >> r;

    auto dfs = [&](auto&& dfs, ll pos, ll cnt, bool limit) -> ll {
        if(cnt > 3) return 0;
        if(pos == (ll)s.size()) {
            return 1;
        }

        if(!limit && dp[pos][cnt] != -1) {
            return dp[pos][cnt];
        }

        ll up = limit ? s[pos] - '0' : 9;
        ll ans = 0;
        
        for(ll d = 0; d <= up; d++) {
            ans += dfs(
                dfs,
                pos + 1,
                cnt + (d != 0),
                limit && (d == up)
            );
        }
        if(!limit) {
            dp[pos][cnt] = ans;
        }
        return ans;
    };
    auto calc = [&](ll x) -> ll {
        if(x < 0) return 0;
        s = to_string(x);
        memset(dp, -1, sizeof(dp));

        return dfs(dfs, 0, 0, 1);
    };
    cout << calc(r) - calc(l - 1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}