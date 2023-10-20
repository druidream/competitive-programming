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
    while (T--) {
        int n; cin >> n;
        if (n == 1) {
            print(1)
            continue;
        }

        if (n % 2 == 1) {
            print(-1)
        } else {
            vi res(1, n);
            int a = n - 1;
            for (int i = 0; i < (n - 1) / 2; i++) {
                res.push_back(a);
                res.push_back(n + 1 - a);
                a -= 2;
            }
            res.push_back(1);
            printInline(res)
        }
    }
    return 0;
}
