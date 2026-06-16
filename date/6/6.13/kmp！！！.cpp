#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(const string& s) {
    int n = s.size();
    vector<int> pi(n);

    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }

        if (s[i] == s[j]) {
            j++;
        }

        pi[i] = j;
    }

    return pi;
}

int longest_pal_prefix(const string& s) {
    string rev = s;
    reverse(rev.begin(), rev.end());

    string t = s + "#" + rev;
    vector<int> pi = prefix_function(t);

    return pi.back();
}

int longest_pal_suffix(const string& s) {
    string rev = s;
    reverse(rev.begin(), rev.end());

    string t = rev + "#" + s;
    vector<int> pi = prefix_function(t);

    return pi.back();
}

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    int l = 0, r = n - 1;

    while (l < r && s[l] == s[r]) {
        l++;
        r--;
    }

    if (l >= r) {
        cout << s << '\n';
        return;
    }

    string left = s.substr(0, l);
    string right = s.substr(r + 1);

    string mid = s.substr(l, r - l + 1);

    int pre_len = longest_pal_prefix(mid);
    int suf_len = longest_pal_suffix(mid);

    string best;

    if (pre_len >= suf_len) {
        best = mid.substr(0, pre_len);
    } else {
        best = mid.substr(mid.size() - suf_len);
    }

    cout << left + best + right << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}