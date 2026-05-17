#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    if(abs(a - b) <= 1 && (a + b) > 0) {
        cout << "YES\n";
    } 
    else {
        cout << "NO\n";
    }

}