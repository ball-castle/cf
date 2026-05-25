#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
https://codeforces.com/problemset/problem/946/C
直接贪心
子串是不需要连续的
前面直接贪心找
能找到就直接用
*/


void solve() {
    string s;
    cin >> s;
    int n = s.size();

    int m = 'a';
    for(int i = 0; i < n; i++) if(s[i] <= m && m <= 'z') s[i] = m, m++;
    if(m > 'z') cout << s << '\n';
    else cout << -1 << '\n';

}








int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    T = 1;
    while(T--) solve();
    return 0;
}