#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<string> s(8);
    int f = 0;
    for(int i = 0; i < 8; i++) cin >> s[i];
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(s[i][j] == s[i][j + 1]) f = 1;
        }
    }
    if(f) {cout << "NO" << '\n'; return 0;}
    cout << "YES" << '\n';
    return 0; 
}