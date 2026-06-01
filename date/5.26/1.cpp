#include <bits/stdc++.h>
using namespace std;
using ll = long long;




/*
https://codeforces.com/contest/2162/problem/E
加入一个数会产生什么样的结果
唯一可能新增的就是旁边的 ? 
！！！还有隔一个的 
结果就是 加入一个数后面如果不影响长度为2和3的就不会新增 后面直接循环就行
所以还需要考虑前面的影响，让前面不添加（分排列和不排列）
最后怎么加 
a[n - 1] a[n] x y z     x != a[n] , x != a[n - 1]
而前面是n个数 都在 [1, n] 之间 考虑是否有数字重复 排列和非排列
非排列 a[n - 1] a[n]   x y a[n]
排列 a[1] a[2] a[3]
*/
ll a[200010], vis[200010];
ll ans[10];
void solve() {
    ll n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) vis[i] = 0;
    for(int i = 1; i <= 3; i++) ans[i] = 0;

    for(int i = 1; i <= n; i++) cin >> a[i], vis[a[i]] = 1;
    int p = -1;
    for(int i = 1; i <= n; i++) if(!vis[i]) {p = i; break;} 
    if(p != -1) {
        ans[1] = p, ans[3] = a[n];
        for(int i = 1; i <= n; i++) if(i != ans[1] && i != ans[3]) {ans[2] = i; break;}
    }
    else for(int i = 1; i <= 3; i++) ans[i] = a[i];
    
    for(int i = 1; i <= k; i++) cout << ans[(i - 1) % 3 + 1] << ' ';
    cout << '\n';
}







int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}