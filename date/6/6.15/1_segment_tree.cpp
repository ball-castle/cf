#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1000000007;

struct Mat {
    ll a[2][2];
};

Mat mul(const Mat &x, const Mat &y) {
    Mat res{};
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            res.a[i][j] = 0;
            for(int k = 0; k < 2; k++) {
                res.a[i][j] = (res.a[i][j] + x.a[i][k] * y.a[k][j]) % MOD;
            }
        }
    }
    return res;
}

Mat MA() {
    Mat m{};
    m.a[0][0] = 1; m.a[0][1] = 1;
    m.a[1][0] = 0; m.a[1][1] = 1;
    return m;
}

Mat MB() {
    Mat m{};
    m.a[0][0] = 1; m.a[0][1] = 0;
    m.a[1][0] = 1; m.a[1][1] = 1;
    return m;
}

struct Node {
    Mat mat, rev;
    bool lazy = false;
};

const int MAXN = 100000 + 5;

int n, q;
string s;
Node seg[MAXN * 4];

void apply_flip(int id) {
    swap(seg[id].mat, seg[id].rev);
    seg[id].lazy ^= 1;
}

void push(int id) {
    if(seg[id].lazy) {
        apply_flip(id * 2);
        apply_flip(id * 2 + 1);
        seg[id].lazy = false;
    }
}

void pull(int id) {
    // 先执行左区间，再执行右区间，所以矩阵是 right * left
    seg[id].mat = mul(seg[id * 2 + 1].mat, seg[id * 2].mat);
    seg[id].rev = mul(seg[id * 2 + 1].rev, seg[id * 2].rev);
}

void build(int id, int l, int r) {
    if(l == r) {
        if(s[l] == 'A') {
            seg[id].mat = MA();
            seg[id].rev = MB();
        } else {
            seg[id].mat = MB();
            seg[id].rev = MA();
        }
        return;
    }

    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    pull(id);
}

void update(int id, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        apply_flip(id);
        return;
    }

    push(id);

    int mid = (l + r) / 2;
    if(ql <= mid) update(id * 2, l, mid, ql, qr);
    if(qr > mid) update(id * 2 + 1, mid + 1, r, ql, qr);

    pull(id);
}

Mat query(int id, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        return seg[id].mat;
    }

    push(id);

    int mid = (l + r) / 2;

    if(qr <= mid) {
        return query(id * 2, l, mid, ql, qr);
    }

    if(ql > mid) {
        return query(id * 2 + 1, mid + 1, r, ql, qr);
    }

    Mat left = query(id * 2, l, mid, ql, qr);
    Mat right = query(id * 2 + 1, mid + 1, r, ql, qr);

    // 仍然是先左后右，所以 right * left
    return mul(right, left);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    cin >> s;
    s = " " + s; // 变成 1-indexed

    build(1, 1, n);

    while(q--) {
        int type;
        cin >> type;

        if(type == 1) {
            int l, r;
            cin >> l >> r;
            update(1, 1, n, l, r);
        } else {
            int l, r;
            ll A, B;
            cin >> l >> r >> A >> B;

            A %= MOD;
            B %= MOD;

            Mat m = query(1, 1, n, l, r);

            ll ansA = (m.a[0][0] * A + m.a[0][1] * B) % MOD;
            ll ansB = (m.a[1][0] * A + m.a[1][1] * B) % MOD;

            cout << ansA << ' ' << ansB << '\n';
        }
    }

    return 0;
}