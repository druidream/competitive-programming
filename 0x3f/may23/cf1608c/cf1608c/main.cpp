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
        vi a(n), b(n);
        int p = -1, q = -1, mx = 0;
        rep(i, n) {
            cin >> a[i];
            if (a[i] > mx) {
                mx = a[i];
                p = i;
            }
        }
        mx = 0;
        rep(i, n) {
            cin >> b[i];
            if (b[i] > mx) {
                mx = b[i];
                q = i;
            }
        }
        string s(n, '0');
        if (p == q) {
            s[p] = '1';
        } else {
            s[p] = '1';
            s[q] = '1';
            priority_queue<pair<int, int>> pqa, pqb;
            int u = a[q], v = b[p];
            rep(i, n) {
                pqa.push({ a[i], i });
                pqb.push({ b[i], i });
            }
            while ((!pqa.empty() && pqa.top().first > u) || (!pqb.empty() && pqb.top().first > v)) {
                while (!pqa.empty() && pqa.top().first > u) {
                    int idx = pqa.top().second;
                    s[idx] = '1';
                    v = min(v, b[idx]);
                    pqa.pop();
                }
                while (!pqb.empty() && pqb.top().first > v) {
                    int idx = pqb.top().second;
                    s[idx] = '1';
                    u = min(u, a[idx]);
                    pqb.pop();
                }
            }
        }
        print(s)
    }
    return 0;
}
