#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[1010][1010];
int s[1010][1010];

int get(int x1, int y1, int x2, int y2) {
    return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
}

bool check(int x, int y, int lx, int ly, int rx, int ry) {
    int h = rx - lx + 1;
    int w = ry - ly + 1;

    int ex = rx - x + 1;
    int ey = ry - y + 1;

    if(ex < lx || ey < ly) return false;

    vector<int> dp(w - y + 1, 0);

    for(int i = lx; i <= ex; i++) {
        for(int j = ly; j <= ey; j++) {
            int ok = 0;
            if(get(i, j, i + x - 1, j + y - 1) == x * y) ok = 1;

            int id = j - ly;

            if(!ok) {
                dp[id] = 0;
                continue;
            }

            if(i == lx && j == ly) {
                dp[id] = 1;
            } else {
                int f = dp[id];
                if(id > 0) f |= dp[id - 1];
                dp[id] = f;
            }
        }
    }

    return dp[w - y];
}

void solve() {
    cin >> n >> m;

    int lx = n + 1, ly = m + 1, rx = 0, ry = 0;
    int cnt = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];

            if(a[i][j] == 'X') {
                lx = min(lx, i);
                ly = min(ly, j);
                rx = max(rx, i);
                ry = max(ry, j);
                cnt++;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (a[i][j] == 'X');
        }
    }

    int h = rx - lx + 1;
    int w = ry - ly + 1;

    int d = h * w - cnt;

    if(d == 0) {
        cout << min(h, w) << '\n';
        return;
    }

    vector<array<int, 3>> v;

    for(int i = 1; i * i <= d; i++) {
        if(d % i) continue;

        int u = i;
        int t = d / i;

        int x = h - u;
        int y = w - t;

        if(x >= 1 && y >= 1) v.push_back({x * y, x, y});

        u = t;
        t = i;

        x = h - u;
        y = w - t;

        if(x >= 1 && y >= 1) v.push_back({x * y, x, y});
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(auto p : v) {
        int x = p[1];
        int y = p[2];

        if(check(x, y, lx, ly, rx, ry)) {
            cout << x * y << '\n';
            return;
        }
    }

    cout << -1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}