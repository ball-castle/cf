#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
https://codeforces.com/problemset/problem/1794/A
模拟实现的题目
关注信息保留最多的
就是找核心!
*/


void solve() {
    ll n;
    cin >> n;
    vector<string> v;
    
    for(int i = 0; i < 2 * n - 2; i++) {
        string s;
        cin >> s;
        if((int)s.size() == n - 1) v.push_back(s);
    }

    reverse(v[0].begin(), v[0].end());
    cout << (v[0] == v[1] ? "YES" : "NO") << '\n'; 
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();

    return 0;

}