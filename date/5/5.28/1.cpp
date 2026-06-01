#include <bits/stdc++.h>
using namespace std;
using ll = long long;

char rev(char s) {
    return s == '+' ? '*' : '+';
}

/*
从特殊到一般，看看能不能从2 ^ k * 2 ^ k到2 ^ (k + 1) * 2 ^ (k + 1)
https://codeforces.com/problemset/problem/610/C
*/


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll k;
    cin >> k;

    vector<string> a;
    a.push_back("+");

    for(int m = 1; m <= k; m++) {
        ll n = a.size();

        vector<string> b(2 * n, string(2 * n, '+'));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                b[i][j] = a[i][j], b[i + n][j] = a[i][j];
                b[i][j + n] = a[i][j], b[i + n][j + n] = rev(a[i][j]);
            } 
        }
        a = b;
    }
    ll n = a.size();
    for(int i = 0; i < n; i++) cout << a[i] << '\n';
    return 0;


}