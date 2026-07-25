#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 2e5 + 5;
ll fa[N], rk[N];


void init(ll n) {
	for(ll i = 1; i <= n; i++) {
		fa[i] = i;
		rk[i] = 1;
	}
}

int find(ll x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void unite(ll x, ll y) {
	ll fx = find(x), fy = find(y);
	if(fx == fy) return;
	if(rk[fx] < rk[fy]) fa[fx] = fy;
	else {
		fa[fy] = fx;
		if(rk[fx] == rk[fy]) rk[fx]++;
	}
}
ll p[200010];
void solve() {
    ll n, x, y;
    cin >> n >> x >> y;

    init(n);
    for(ll i = 1; i <= n; i++) cin >> p[i];

    for(ll i = 1; i <= n; i++) {
        if(i + x <= n) unite(i, i + x);
        if(i + y <= n) unite(i, i + y);
    }

    for(ll i = 1; i <= n; i++) {
        if(find(i) != find(p[i])) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}