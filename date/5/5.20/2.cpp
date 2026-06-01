#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
二分图 = 能把所有点分成两组，使得每条边都连接不同组的图。
没有奇数长度的环就是二分图，能被黑白染色
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    vector<vector<ll>> g(n + 1);

    for(ll i = 1; i < n; i++) {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<ll> c(n + 1, -1);
    queue<ll> q;

    c[1] = 0;
    q.push(1);

    ll ct[2] = {1, 0};
    
    while(!q.empty()) {
        ll u = q.front();
        q.pop();

        for(ll v : g[u]) {
            if(c[v] == -1) {
                c[v] = 1 - c[u];
                ct[c[v]]++;
                q.push(v);
            }
        }
    }
    cout << ct[0] * ct[1] - (n - 1) << '\n';
    return 0;
}