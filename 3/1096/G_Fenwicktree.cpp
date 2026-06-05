#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
这种其实都算是计数问题
计数问题大都可以转化成简单的顺序或逆序计算
结果
*/

/*
    区间查询 前缀和  
    区间修改 差分
    单点修改 区间查询  单点查询 区间修改 树状数组  只能做可逆的操作
    维护集合有序 平衡树（只有找小于x的个数 对于某个区间整体修改仍然保持有序）其余都能用set
    线段树可以做好多好多事情 查询小于x的个数也可以用线段树维护桶

*/   


inline ll read() {
    ll x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
    return x * f;
}



ll n;
ll a[200010];
void solve() {
    n = read();
    for(int i = 1; i <= n; i++)  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    T = read();
    while(T--) solve();
    return 0;
}