#include <bits/stdc++.h>
using namespace std;
using ll = long long;


/*
记住一个原则就是queue是push front pop
*/

ll vis[10][10];
void solve() {
    ll n;
    cin >> n;
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) vis[i][j] = 0;
    }
    ll x1 = 0, y1 = 0;
    for(int i = 1; i <= n; i++) {
        int r, c;
        cin >> r >> c;
        if(n == 3 && i == 1) x1 = r, y1 = c; 
        vis[r][c] = 1;
    }

    for(int i = 1; i <= n; i++) {
        int r, c;
        cin >> r >> c;
        vis[r][c] = 2;
    }   
    
    ll x = 0, y = 0;
    ll f = 0;
    for(int i = 1; i <= 3; i++) {
        if(f) break;
        for(int j = 1; j <= 3; j++) {
            if(vis[i][j]) continue;
            vis[i][j] = 1;
            vis[x1][y1] = 0;
            if(vis[i][1] == 1 && vis[i][2] == 1 && vis[i][3] == 1) f = 1; 
            if(vis[1][j] == 1 && vis[2][j] == 1 && vis[3][j] == 1) f = 1; 
            if(vis[3][1] == 1 && vis[2][2] == 1 && vis[1][3] == 1) f = 1; 
            if(vis[3][3] == 1 && vis[2][2] == 1 && vis[1][1] == 1) f = 1;
            if(f) {x = i, y = j; cout << x << ' ' << y << '\n'; return;} 
            vis[i][j] = 0;
        }    
    }
    cout << "Columbina Hyposelenia" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}