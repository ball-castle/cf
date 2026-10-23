#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a[1000010];



/*
对于博弈论的题 需要找到最小必败情况


*/
void solve() {
    ll n;
    cin >> n;

    ll ct0 = 0, ct1 = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] % 2 == 0) ct0++;
        else ct1++;
    }

    if((ct1 == 1 && ct0 == 1) || (ct1 == 3 && ct0 == 0)) cout << "Larpity" << '\n';
    else cout << "Moggity" << '\n';                      
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    ll T = 1;
    cin >> T;
    while(T--) solve();
    return 0;

}