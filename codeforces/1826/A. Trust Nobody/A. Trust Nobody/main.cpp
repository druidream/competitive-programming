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
        vi l(n); rep(i, n) cin >> l[i];
        sort(l.begin(), l.end(), greater<>());
        int ans = -1;
        // 数字大的比数字小的更容易成为 liar
        // 假设有 x 个 liar，那么 l[i] > x 的都成为 liar，检查这个 cnt 是否等于 x
        // x 的范围是 [0...n]
        for (int x = 0; x <= n; x++) {
            int cnt = 0;
            rep(i, n) {
                if (l[i] > x) cnt++;
            }
            if (cnt == x) {
                ans = x;
                break;
            }
        }
        print(ans)
    }
    return 0;
}
