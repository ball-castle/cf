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

signed main() {
    printf("%lld", a[-1]);
    return 0;
}