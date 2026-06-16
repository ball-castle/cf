#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    string s;
    cin >> n >> m >> s;

    int x = 0, y = 0; // 当前相对起点的位移
    int minx = 0, maxx = 0;
    int miny = 0, maxy = 0;

    int ansx = 1, ansy = 1; // 当前最优起点

    for(char ch : s) {
        if(ch == 'U') x--;
        else if(ch == 'D') x++;
        else if(ch == 'L') y--;
        else if(ch == 'R') y++;

        minx = min(minx, x);
        maxx = max(maxx, x);
        miny = min(miny, y);
        maxy = max(maxy, y);

        int height = maxx - minx + 1;
        int width = maxy - miny + 1;

        if(height > n || width > m) {
            break;
        }

        ansx = 1 - minx;
        ansy = 1 - miny;
    }

    cout << ansx << ' ' << ansy << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}