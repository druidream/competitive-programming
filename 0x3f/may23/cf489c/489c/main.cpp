#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, x, n) for (int i = x; i < n; i++)
#define rev(i, n) for (int i = n - 1; i >= 0; i--)
#define LSOne(S) ((S) & (-S))
#define roundUp(a, b) ((a + b - 1) / b)
#define print(x) cout << x << '\n';
#define printBool(x) cout << (x ? "Yes" : "No") << '\n';
#define printInline(a) rep(i, a.size()) cout << a[i] << ' '; cout << '\n';

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

vector<string> solve() {
    int m, s; cin >> m >> s;
    if (s == 0 && m != 1) return { "-1", "-1" };
    if (s > m * 9) return { "-1", "-1" };
    vi mn(m, 0), mx(m, 0);
    int t = s - 1;
    mn[0] = 1;
    for (int i = m - 1; i >= 0; i--) {
        if (t == 0) break;
        if (t > 9) {
            mn[i] += 9;
            t -= 9;
        } else {
            mn[i] += t;
            t = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        if (s == 0) break;
        if (s > 9) {
            mx[i] = 9;
            s -= 9;
        } else {
            mx[i] = s;
            s = 0;
        }
    }
    string a, b;
    rep(i, m) {
        a += '0' + mn[i];
        b += '0' + mx[i];
    }
    return { a, b };
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<string> arr = solve();
    cout << arr[0] << ' ' << arr[1] << endl;
    return 0;
}
