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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    int inf = 0x3f3f3f3f;
    while (T--) {
        int n; cin >> n;
        int a = inf, b = inf, c = inf;
        while (n--) {
            int m; cin >> m;
            string s; cin >> s;
            if (s == "11") {
                a = min(a, m);
            } else if (s == "01") {
                b = min(b, m);
            } else if (s == "10") {
                c = min(c, m);
            }
        }
        int ans = min(a, b + c);
        if (ans == inf) ans = -1;
        print(ans)
    }
    return 0;
}
