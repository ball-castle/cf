#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll x[200010];
ll t[200010];
ll tv[200010];
void solve() {
    ll n;
    cin >> n;
    
    for(int i = 1; i <= n; i++) cin >> x[i];
    for(int i = 1; i <= n; i++) cin >> t[i];

    ll f = 0;  
    ll t0 = 0;
    
    for(int i = 2; i <= n; i++) {
        t0 += x[i] - x[i - 1];
        if(t0 > t[i]) f = 1;
        tv[i] = t0;
    }

    for(int i = n - 1; i >= 1; i--) {
        t0 += x[i + 1] - x[i];
        if(t0 - tv[i] > t[i]) f = 1;
        tv[i] = t0; 
    }

    for(int i = 2; i <= n; i++) {
        t0 += x[i] - x[i - 1];
        if(t0 - tv[i]> t[i]) f = 1;
        tv[i] = t0;
    }

    cout << (f ? "No" : "Yes") << '\n';


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    while(T--) solve();

    return 0;
}