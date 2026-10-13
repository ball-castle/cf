#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a[200005];
ll tree[200005 * 4]; // 我们是1 based


// 维护最小值 有改 有查


void pushup(int node) {
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}


void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = a[l];
        return;
    }

    int mid = (l + r) >> 1;

    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);

    pushup(node);
}

ll query(int node, int l, int r, int L, int R) {
    if (R < l || r < L) return 4e18;    // 既然没有贡献 不在我们需要查的范围内 我们就返回一个很大的数

    if (L <= l && r <= R) {
        return tree[node];
    }

    int mid = (l + r) >> 1;

    return min(query(node * 2, l, mid, L, R)
        , query(node * 2 + 1, mid + 1, r, L, R));
}

void update(int node, int l, int r, int pos, ll val) { // 单点修改
    if (l == r) {
        tree[node] = val;
        return;
    }

    int mid = (l + r) >> 1;

    if (pos <= mid) {
        update(node * 2, l, mid, pos, val);
    } else {
        update(node * 2 + 1, mid + 1, r, pos, val);
    }

    pushup(node);
}

void solve() {
    ll n, m;
    cin >> n >> m;

    for(ll i = 1; i <= n; i++) cin >> a[i];

    build(1, 1, n);

    while(m--) {
        ll op;
        cin >> op;

        if(op == 1) {
            int i;
            ll v;
            cin >> i >> v;

            update(1, 1, n, i + 1, v);
        }
        else {
            int l, r;
            cin >> l >> r;
            
            cout << query(1, 1, n, l + 1, r) << '\n';
        }
    }
}






int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    while(T--) solve();

    return 0;
}