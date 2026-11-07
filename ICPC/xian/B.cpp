#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 找规律 就是找性质
// 顺存 然后先考虑相邻的 那就是栈




ll a[400010];
ll b[200010];
ll fa[400010];
ll rk[400010];
ll n;
ll l[200010];

void init(ll n) {
	for(ll i = 1; i <= 2 * n; i++) {
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

bool same(ll x, ll y) {
	return find(x) == find(y);
}




void solve() {
    cin >> n;
    init(n);
    string ans(2 * n + 1, ' ');
    stack<ll> st;

    for(ll i = 1; i <= 2 * n; i++) cin >> a[i];
    for(ll i = 1; i <= n; i++) b[i] = -1; 
    for(ll i = 1; i <= 2 * n; i++) {
        if(b[a[i]] == -1) b[a[i]] = i;
        else unite(b[a[i]], i);
    }


    for(int i = 1; i <= 2 * n; i++) {
        if(!st.empty() && !same(st.top(), i)) {
            int j = st.top();
            st.pop();
            ans[j] = '(';
            ans[i] = ')';

            unite(j, i);
        }
        else {
            st.push(i);
        }
    }

    int r = st.top(); st.pop();
    int l = st.top(); st.pop();

    ans[l] = '(';
    ans[r] = ')';

    for(int i = 1; i <= 2 * n; i++) cout << ans[i];
    cout << '\n';
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;

    cin >> T;

    while(T--) solve();
    return 0;
}