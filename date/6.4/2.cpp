#include <bits/stdc++.h>
using namespace std;

using ll = long long;

inline ll read() {
    ll x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
    return x * f;
}

void solve() {
    int n, m, k;
    n = read(), m = read(), k = read();
    
    vector<array<int, 3>> f(k);
    for(int i = 0; i < k; i++) {
        int r, c;
        r = read(), c = read();
        c--;
        f[i] = {c, r, i};
    }
    sort(f.begin(), f.end());
    
    ll ans = 0;
    vector<ll> a(k);
    int x = 0, y = 0;
    vector<int> v(k);
    for(auto [c, r, i] : f) {
        if(r > x) {
            ans += 1LL * (r - x) * c;
            x = r;
            y = c;
            v[i] = 1;
        }
    }
    ans += 1LL * (n - x) * m;
    
    for(int j = 0; j < k; j++) {
        auto [c, r, i] = f[j];
        if(!v[i]) {
            continue;
        }
        int L = j - 1, R = j + 1;
        while(L >= 0 && !v[f[L][2]]) {
            L--;
        }
        while(R < k && !v[f[R][2]]) {
            R++;
        }
        int x = L >= 0 ? f[L][1] : 0;
        int y = L >= 0 ? f[L][0] : 0;
        int rx = R < k ? f[R][1] : n;
        int ry = R < k ? f[R][0] : m;
        ll res = 0;
        res -= 1LL * (r - x) * c;
        res -= 1LL * (rx - r) * ry;
        for(int u = j + 1; u < R; u++) {
            auto [c, r, _] = f[u];
            if(r > x) {
                res += 1LL * (r - x) * c;
                x = r;
                y = c;
            }
        }
        res += 1LL * (rx - x) * ry;
        a[i] = res;
    }
    cout << ans << "\n";
    for(int i = 0; i < k; i++) {
        cout << a[i] << " \n"[i == k - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    t = read();
    while(t--) {
        solve();
    }
    
    return 0;
}
