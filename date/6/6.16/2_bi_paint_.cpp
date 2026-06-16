#include <bits/stdc++.h>
using namespace std;
using ll = long long;


/*
只要保证1 2, 3 4, 5 6 两两不一样就行
二分图染色
*/


void solve() {
    ll n;
    cin >> n;

    ll m = 2 * n;
    vector<ll> a(n), b(n);
    vector<vector<ll>> adj(m + 1);

    auto add = [&](ll u, ll v) {
        adj[u].push_back(v);
        adj[v].push_back(u); 
    };

    for(ll i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        add(a[i], b[i]);
    }

    for(ll i = 1; i <= m; i += 2) {
        add(i, i + 1);
    } 

    vector<ll> col(m + 1, 0);

    for(ll i = 1; i <= m; i++) { // template
        if(col[i]) continue;
        
        queue<ll> q;
        col[i] = 1;
        q.push(i);
        
        while(!q.empty()) {
            ll u = q.front();
            q.pop();

            for(ll v : adj[u]) {
                if(!col[v]) {
                    col[v] = 3 - col[u];
                    q.push(v);
                }
            }
        }
    }
    for(ll i = 0; i < n; i++) {
        cout << col[a[i]] << ' ' << col[b[i]] << '\n';
    }
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}