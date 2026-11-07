#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    stack<ll> st;
    ll ans = 0;

    st.push(a[0]);
    for(ll i = 1; i < n; i++) {
        if(a[i] >= st.top()) st.pop(), st.push(a[i]);
        if(a[i] < st.top()) ans++;
    }

    cout << ans << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;

}