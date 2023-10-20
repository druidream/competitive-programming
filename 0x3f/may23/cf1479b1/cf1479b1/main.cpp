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
    int n; cin >> n;
    int pre = 0, cnt = 0, tot = 0;
    rep(i, n) {
        int x; cin >> x;
        if (x == pre) {
            cnt++;
            if (cnt <= 2) {
                tot += 1;
            }
        } else {
            pre = x;
            cnt = 1;
            tot += 1;
        }
    }
    print(tot)
    return 0;
}
