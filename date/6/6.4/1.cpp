#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
对于排列的mex好看 所以对于这道题直接把它补齐
*/

inline ll read() {
    ll x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
    return x * f;
}
ll vis[100010], a[100010];
void solve() {
    ll n, k;
    n = read(), k = read();
    for(ll i = 0; i <= n; i++) vis[i] = 0;
    for(ll i = 1; i <= n; i++) a[i] = read();
    for(ll i = 1; i <= n; i++) vis[a[i]] = 1;
    for(ll i = 0; i <= n; i++) if(!vis[i]) a[n + 1] = i; 
    
    for(ll i = 1; i <= n; i++) cout << a[(i + (n + 1) - k % (n + 1) - 1) % (n + 1) + 1] << ' ';
    cout << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    T = read();
    while(T--) solve();
    return 0;
}