#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
https://codeforces.com/problemset/problem/1092/A
*/
void solve() {
    ll n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        char s = i % k + 'a';
        cout << s;
    }
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