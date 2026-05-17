#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
ll a[1010], b[1010], dp[1010];
int in[1010];
vector<int> e[1010], tp;

void solve() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        e[i].clear();
        in[i] = 0;
        dp[i] = 0;
    }

    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        in[y]++;
    }

    int ok = 1;
    for(int i = 1; i <= n; i++)
        if(a[i]) ok = 0;

    if(ok) {
        cout << 0 << '\n';
        return;
    }

    for(int t = 1; t <= n; t++) {
        for(int i = 1; i <= n; i++) b[i] = 0;

        for(int i = 1; i <= n; i++) {
            if(a[i] > 0) {
                a[i]--;
                for(auto j : e[i]) b[j]++;
            }
        }

        int f = 1;
        for(int i = 1; i <= n; i++) {
            a[i] += b[i];
            if(a[i]) f = 0;
        }

        if(f) {
            cout << t << '\n';
            return;
        }
    }

    queue<int> q;
    tp.clear();

    for(int i = 1; i <= n; i++)
        if(in[i] == 0) q.push(i);

    while(q.size()) {
        int x = q.front();
        q.pop();
        tp.push_back(x);

        for(auto y : e[x]) {
            in[y]--;
            if(in[y] == 0) q.push(y);
        }
    }

    int s = 1;
    for(int i = 1; i <= n; i++)
        if(e[i].empty()) s = i;

    dp[s] = 1;

    for(int i = n - 1; i >= 0; i--) {
        int x = tp[i];

        for(auto y : e[x]) {
            dp[x] += dp[y];
            dp[x] %= 998244353;
        }
    }

    ll ans = n;

    for(int i = 1; i <= n; i++) {
        ans += a[i] % 998244353 * dp[i] % 998244353;
        ans %= 998244353;
    }

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