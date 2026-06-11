#include <bits/stdc++.h>
using namespace std;

using ll = long long;

inline ll read() {
    ll x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
    return x * f;
}


/*
化成 1 2 3 4 5 6 
对于m个有用怪来说
ans = sum - sum(1, m)
但有用怪不能完全用set 比如 4 4 应该算 1 2

那我们如何去维护有用怪的集合
对于任何 x  小于等于x的个数 kx <= x
d[x] = x - kx >= 0

那么加入一个数之后 相当于对于一段区间进行修改
*/
const int N = 200010;

ll a[N];

// mn[node]：当前区间 d[x] 的最小值
// lazy[node]：当前节点已经整体加过某个值，但是还没传给儿子
// pos[node]：当前区间最小值出现的位置
ll mn[N * 4], lazy[N * 4];
int pos[N * 4];

// 把左右儿子的信息往上传
void pushup(int node) {
    if(mn[node * 2] <= mn[node * 2 + 1]) {
        mn[node] = mn[node * 2];
        pos[node] = pos[node * 2];
    } else {
        mn[node] = mn[node * 2 + 1];
        pos[node] = pos[node * 2 + 1];
    }
}

// 给 node 这个区间整体加 val
void apply(int node, int l, int r, ll val) {
    mn[node] += val;
    lazy[node] += val;
}

// 把 lazy 标记下传给左右儿子
void pushdown(int node, int l, int r) {
    if(lazy[node] == 0) return;

    int mid = (l + r) >> 1;

    apply(node * 2, l, mid, lazy[node]);
    apply(node * 2 + 1, mid + 1, r, lazy[node]);

    lazy[node] = 0;
}

// 建树
void build(int node, int l, int r) {
    lazy[node] = 0;

    if(l == r) {
        // 初始时没有任何怪物
        // d[x] = x - count(<=x)
        // count(<=x) = 0
        // 所以 d[x] = x
        mn[node] = l;
        pos[node] = l;
        return;
    }

    int mid = (l + r) >> 1;

    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);

    pushup(node);
}

// 区间修改：把 [L, R] 全部加 val
void modify(int node, int l, int r, int L, int R, ll val) {
    if(L <= l && r <= R) {
        apply(node, l, r, val);
        return;
    }

    pushdown(node, l, r);

    int mid = (l + r) >> 1;

    if(L <= mid) modify(node * 2, l, mid, L, R, val);
    if(R > mid) modify(node * 2 + 1, mid + 1, r, L, R, val);

    pushup(node);
}

void solve() {
    int n = read();

    for(int i = 1; i <= n; i++) {
        a[i] = read();
    }

    build(1, 1, n);

    ll sum = 0; // 当前有用怪的原始数值之和
    ll cnt = 0; // 当前有用怪数量

    for(int i = 1; i <= n; i++) {
        sum += a[i];
        cnt++;

        // 加入一个 a[i]
        // 对于所有 x >= a[i]，count(<=x) 都会 +1
        // 所以 d[x] = x - count(<=x) 都会 -1
        modify(1, 1, n, a[i], n, -1);

        // 如果最小 d[x] < 0，说明某个前缀数量太多，不合法
        // 需要删掉一个怪，删的位置就是 pos[1]
        if(mn[1] < 0) {
            sum -= pos[1];
            cnt--;

            // 删除 pos[1] 这个怪
            // 对所有 x >= pos[1]，count(<=x) -1
            // 所以 d[x] +1
            modify(1, 1, n, pos[1], n, +1);
        }

        // 当前答案 = 有用怪总和 - 1 - 2 - ... - cnt
        if(i == n) cout << sum - cnt * (cnt + 1) / 2 << " \n"[i == n];
    }
}

int main() {
    int T = read();

    while(T--) {
        solve();
    }

    return 0;
}