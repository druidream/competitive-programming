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

int gcd(int a, int b) {
    return b > 0 ? gcd(b, a % b) : a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vi a(n); rep(i, n) cin >> a[i];
        if (n == 1) {
            print(0)
            continue;
        }
        vi d;
        for (int i = 0; i < n / 2; i++) {
            d.push_back(abs(a[i] - a[n - i - 1]));
        }
        int g = d[0];
        for (int i = 1; i < d.size(); i++) {
            g = gcd(g, d[i]);
        }
        print(g)
    }
    return 0;
}
