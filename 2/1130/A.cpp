#include <bits/stdc++.h>
using namespace std;
using ll = long long;




void solve() {
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n + 1);

    for(int i = 1; i <= n; i++) cin >> a[i];
    
    if(k == 1) {
        cout << -1 << '\n';
        return;
    }    
    


    ll mx = -4e18;
    ll mi = 4e18;
    ll idx = -1, idi = -1; 
    
    for(int i = 1; i <= n - k + 1; i++) {
        if(a[i] > mx) {
            idx = i;
            mx = a[i];
        }
    }

    for(int i = n; i > n - k + 1; i--) {
        if(a[i] < mi) {
            idi = i;
            mi = a[i];
        }
    }
    if(mx < mi) {
        cout << -1 << '\n';
        return;
    }
    

    cout << idx << ' ' << idi << '\n';

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T = 1;
    cin >> T;
    while(T--) solve();
}