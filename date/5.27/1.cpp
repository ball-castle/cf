#include <bits/stdc++.h>
using namespace std;
using ll = long long;


/*
暴力 + 剪枝
在二维里面只要有两个点在同一象限里，那么就全部是坏点
注意实现细节 比如一开始归零的时候 后面要排除相等的情况等等
*/

struct node {
    ll a, b, c, d, e;
};

ll p[1010][10];
ll v1[1010][1010];
ll vis[1010];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    for(int i = 1; i <= n; i++) { 
        for(int j = 1; j <= 5; j++) cin >> p[i][j];
    }
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= 5; j++) p[i][j] -= p[1][j];
    }
    for(int j = 1; j <= 5; j++) p[1][j] = 0;
    if(n > 33) {
        cout << 0 << '\n';
        return 0;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= 5; k++) v1[i][j] += p[i][k] * p[j][k];
        } 
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                if(i == j || i == k || j == k) continue;
                ll ans = 0;
                ans = v1[j][k] - v1[i][k] - v1[i][j] + v1[i][i];
                if(ans > 0) vis[i] = 1;
            }
        }
    }
    ll ct = 0;
    for(int i = 1; i <= n; i++) if(!vis[i]) ct++;
    cout << ct << '\n';
    for(int i = 1; i <= n; i++) if(!vis[i]) cout << i << ' ';
    cout << '\n';
    return 0;    


}