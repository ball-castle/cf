#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
构造还是考虑过程
这题考虑邻接表不好
局部贪心增量构造其实不太行
https://codeforces.com/contest/232/problem/A
还是考虑先完全再试着补
*/

ll c2(ll x) {
    return x * (x - 1) / 2;
}


ll c3(ll x) {
    return x * (x - 1) * (x - 2) / 6;
}





bool vis[110][110];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll k;
    cin >> k;

    ll n = 0;

    ll p = 3;
    while(p + 1 <= 100 && c3(p + 1) <= k) p++; // 这个写法蛮不错的
    n = p, k -= c3(p);

    for(ll i = 1; i <= p; i++) {
        for(ll j = i + 1; j <= p; j++) vis[i][j] = 1, vis[j][i] = 1;
    }
    //这个时候考虑加入一个点将它缩小 有那题 +2 -1 前面先尽可能做的感觉了
    while(k > 0) {
        ll s = 2;
        while(s + 1 <= p && c2(s + 1) <= k) s++; // 写得好
        n++;
        for(ll i = 1; i <= s; i++) vis[i][n] = vis[n][i] = 1;
        k -= c2(s);
    }
    cout << n << '\n';
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= n; j++) cout << vis[i][j];
        cout << '\n';
    }

    return 0;
}