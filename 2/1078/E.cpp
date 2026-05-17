#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll NEG = -(1LL << 60);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    
    while (T--) {
        int n, m;
        cin >> n >> m;

        int N = n * m;

        vector<ll> a(N), dpS(N), dpT(N);
        vector<ll> rowPref(N), colPref(N);

        auto id = [&](int i, int j) {
            return i * m + j;
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[id(i, j)];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int cur = id(i, j);

                if (i == 0 && j == 0) {
                    dpS[cur] = a[cur];
                } else {
                    ll best = NEG;
                    if (i > 0) best = max(best, dpS[id(i - 1, j)]);
                    if (j > 0) best = max(best, dpS[id(i, j - 1)]);
                    dpS[cur] = best + a[cur];
                }
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int cur = id(i, j);

                if (i == n - 1 && j == m - 1) {
                    dpT[cur] = a[cur];
                } else {
                    ll best = NEG;
                    if (i + 1 < n) best = max(best, dpT[id(i + 1, j)]);
                    if (j + 1 < m) best = max(best, dpT[id(i, j + 1)]);
                    dpT[cur] = best + a[cur];
                }
            }
        }

        ll maxS = dpS[id(n - 1, m - 1)];

        for (int i = 0; i < n; i++) {
            ll rowMax = NEG;

            for (int j = 0; j < m; j++) {
                int cur = id(i, j);

                ll val = dpS[cur] + dpT[cur] - a[cur];

                rowMax = max(rowMax, val);
                rowPref[cur] = rowMax;

                if (i == 0) {
                    colPref[cur] = val;
                } else {
                    colPref[cur] = max(colPref[id(i - 1, j)], val);
                }
            }
        }

        ll ans = maxS;

        int i = n - 1, j = m - 1;

        while (true) {
            int cur = id(i, j);

            ll avoid = NEG;

            if (i + 1 < n && j - 1 >= 0) {
                avoid = max(avoid, rowPref[id(i + 1, j - 1)]);
            }

            if (i - 1 >= 0 && j + 1 < m) {
                avoid = max(avoid, colPref[id(i - 1, j + 1)]);
            }

            ll through = maxS - 2 * a[cur];
            ll cand = max(avoid, through);

            ans = min(ans, cand);

            if (i == 0 && j == 0) break;

            if (i == 0) {
                j--;
            } else if (j == 0) {
                i--;
            } else {
                if (dpS[id(i - 1, j)] >= dpS[id(i, j - 1)]) {
                    i--;
                } else {
                    j--;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}