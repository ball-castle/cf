#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<string> s = {
        "fuquan", "anshun", "zhijin", "sinan", "anlong", "dafang", "puding", "liping", 
        "shiqian", "zhenfeng"
    };
    ll n = s.size();
    string a, b;
    cin >> a >> b;
    string c = a + b;
    ll f = 0;
    for(int i = 0; i < n; i++) {
        if(c == s[i]) f = 1;
    }      
    cout << (f ? "Yes" : "No") << '\n';
    return 0;
}