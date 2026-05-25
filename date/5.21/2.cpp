#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
https://codeforces.com/problemset/problem/1310/B


*/

int fav[200005];
int dp[200005][4], ndp[200005][4];
void solve() {
    int n, k;
    cin >> n >> k;

    int N = 1 << n;

    for(int i = 1; i <= N; i++) fav[i] = 0;
    for(int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        fav[x] = 1;
    }

    int sz = 0;

    for(int i = 1; i <= N; i += 2) {
        sz++;
        for(int j = 0; j < 4; j++) dp[sz][j] = -1;
        int a = fav[i];
        int b = fav[i + 1];
        int val = a | b;
        dp[sz][a * 2 + b] = max(dp[sz][a * 2 + b], val);
        dp[sz][b * 2 + a] = max(dp[sz][b * 2 + a], val);
    }

    while(sz > 1) {
        int ns = 0;
        for(int i = 1; i <= sz; i += 2) {
            ns++;
            for(int j = 0; j < 4; j++) ndp[ns][j] = -1;

            for(int s1 = 0; s1 < 4; s1++) {
                if(dp[i][s1] == -1) continue;

                int u1 = s1 / 2;
                int l1 = s1 % 2;

                for(int s2 = 0; s2 < 4; s2++) {
                    if(dp[i + 1][s2] == -1) continue;

                    int u2 = s2 / 2;
                    int l2 = s2 % 2;

                    int base = dp[i][s1] + dp[i + 1][s2];

                    for(int x = 0; x < 2; x++) {
                        int uw, ul;

                        if(x == 0) uw = u1, ul = u2;
                        else uw = u2, ul = u1;
                        for(int y = 0; y < 2; y++) {
                            int lw;

                            if(y == 0) lw = l1;
                            else lw = l2;

                            for(int z = 0; z < 2; z++) {
                                int nl;

                                if(z == 0) nl = lw;
                                else nl = ul;

                                int val = base;
                                val += u1 | u2;
                                val += l1 | l2;
                                val += lw | ul;

                                int nsid = uw * 2 + nl;
                                ndp[ns][nsid] = max(ndp[ns][nsid], val);
                            }
                        }
                    }
                }
            }
        }

        sz = ns;

        for(int i = 1; i <= sz; i++) {
            for(int j = 0; j < 4; j++) dp[i][j] = ndp[i][j];
        }
    }

    int ans = 0;

    for(int s = 0; s < 4; s++) {
        if(dp[1][s] == -1) continue;

        int u = s / 2;
        int l = s % 2;

        ans = max(ans, dp[1][s] + (u | l));
    }

    cout << ans << '\n';
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    T = 1;
    while(T--) solve();

    return 0;

}