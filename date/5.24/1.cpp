#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
核心矛盾 在某个周期里 有多个核心朝一个内存单元
所以对于某个周期关注内存单元有多少个核心朝着他
如果一个内存单元被锁定了，向它再投的也会被锁定
很多时候实现不来是因为没利用好内存，空间

有序的思维
哪个核心被锁 ans[i];
哪个内存被锁 c[i]
将名词转化成变量

继续存储
每一轮想写i的 w[i]
vector<int> w[k + 1];重点在于翻译
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, k; // n 核心 m 周期 k内存
    cin >> n >> m >> k;

    vector<vector<ll>> a(n + 1, vector<ll>(m + 1)); // i 核心 j 周期

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) cin >> a[i][j];
        
    }

    vector<ll> ans(n + 1, 0);  
    vector<bool> c(k + 1, 0);  

    for(int i = 1; i <= m; i++) { // 枚举周期
        vector<vector<ll>> w(k + 1); // w[x] 表示本周期想写内存 x 的核心

        for(int j = 1; j <= n; j++) { // 枚举核心
            if(ans[j]) continue;

            ll cell = a[j][i]; // 第 j 个核心在第 i 个周期想写的内存

            if(cell == 0) continue; // 什么都不做

            if(c[cell]) ans[j] = i; // 如果这个内存已经被锁，核心 j 立即被锁
            else w[cell].push_back(j); // 否则先记录下来，之后统一判断本周期有没有冲突
        }

        // 统一处理本周期的冲突
        for(int cell = 1; cell <= k; cell++) {
            if(w[cell].size() >= 2) {      // 多个核心同时写同一个未锁内存，发生死锁
                c[cell] = true;
                for(ll co : w[cell]) ans[co] = i;
            }
        }
    }

    for(int i = 1; i <= n; i++) cout << ans[i] << '\n';

    return 0;
}