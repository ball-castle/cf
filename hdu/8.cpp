#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;
const ll mod = 998244353;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
    return x * f;
}

struct node {
    ll sum1, sum2;
}tr[400010];

node operator + (node a, node b) {
    return {(a.sum1 + b.sum1) % mod, (a.sum2 + b.sum2) % mod};
}

#define ls (u << 1)
#define rs (u << 1 | 1)
#define mid ((l + r) >> 1)

int tag[400010], a[100010];

void ad(int u, int l, int r, int vl) {
    int ln = r - l + 1;
    auto [sum1, sum2] = tr[u];
    int tsum1 = (sum1 + ln * vl % mod) % mod;
    int tsum2 = (sum2 + sum1 * 2 * vl % mod + vl * vl % mod * ln % mod) % mod;
    tr[u] = {tsum1, tsum2}; tag[u] = (tag[u] + vl) % mod;
}

void pushdown(int u, int l, int r) {
    ad(ls, l, mid, tag[u]); ad(rs, mid + 1, r, tag[u]); tag[u] = 0;
}

void build(int u, int l, int r) {
    tag[u] = 0;
    if(l == r) return tr[u] = {a[l], a[l] * a[l] % mod}, void();
    build(ls, l, mid); build(rs, mid + 1, r);
    tr[u] = tr[ls] + tr[rs];
}

void add(int u, int l, int r, int ql, int qr, int vl) {
    if(l > qr || r < ql) return ;
    if(l >= ql && r <= qr) return ad(u, l, r, vl), void();
    pushdown(u, l, r); add(ls, l, mid, ql, qr, vl); add(rs, mid + 1, r, ql, qr, vl);
    tr[u] = tr[ls] + tr[rs];
}

node qry(int u, int l, int r, int ql, int qr) {
    if(l > qr || r < ql) return {0, 0};
    if(l >= ql && r <= qr) return tr[u];
    pushdown(u, l, r); return qry(ls, l, mid, ql, qr) + qry(rs, mid + 1, r, ql, qr);
}


void solve() {
    ll n = read(), q = read();
    for(int i = 1; i <= n; i++) a[i] = read();
    build(1, 1, n);
    while(q--) {
        int op = read(), l = read(), r = read();
        if(op == 1) add(1, 1, n, l, r, read());
        else {
            auto [sum1, sum2] = qry(1, 1, n, l, r);
            //printf("%lld %lld\n", sum2, sum1);
            printf("%lld\n", (sum1 * sum1 % mod - sum2 + mod) * 499122177 % mod);
        }
        //printf("%lld %lld\n", tr[1].sum1, tr[1].sum2);
    }
}

signed main() {
    int T = read();
    while(T--) solve();
    return 0;
}