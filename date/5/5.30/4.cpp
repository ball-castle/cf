#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// https://codeforces.com/problemset/problem/898/D 维护一个区间

int flag[200010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n + 2);
    
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.begin() + n + 1);
    ll ans = 0;
    ll ct = 0, q1 = 1, q2 = 0;
    if(k == 1) {cout << n << '\n'; return 0;}
    for(int i = 1; i <= n; i++) {
        q2++; ct++;
        while(q1 < i && (a[q1] <= a[q2] - m || flag[q1])) 
            ct -= !flag[q1], q1++;
        int tip = q2;
        while(ct >= k) {
            flag[tip] = 1; ct--; ans++;
        }
    }
    // for(int i = 1; i <= n - k; i++) {
    //     q1 = i;
    //     while(a[q2] < a[q1] + m && q2 <= n) q2++, ct++;
    //     q2--, ct--;
    //     if(ct >= k) ans += ct - k + 1, ct = k - 1;
    //     ct--;
    // }
    
    cout << ans << '\n';
    return 0;

}   