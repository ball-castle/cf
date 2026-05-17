#include <bits/stdc++.h>
using namespace std;

int a[210];


void solve() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];
    int f = 0;
    
    sort(a + 1, a + n + 1, [&](int x, int y) {return x > y;});
    for(int i = 1; i <= n - 1; i++) {
        if(a[i] == a[i + 1]) {f = 1; break;}
    }

    if(f) {cout << -1 << '\n'; return;}
    for(int i = 1; i <= n; i++) cout << a[i] << ' ';
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