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
        int n, m; cin >> n >> m;
        vi deg(n + 1, 0);
        vector<vector<int>> g(n + 1, vector<int>());
        rep(i, m) {
            int a, b; cin >> a >> b;
            deg[a]++;
            deg[b]++;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        for (int i = 1; i <= n; i++) {
            if (deg[i] == 1) {
                int u = g[i][0];
                for (auto v : g[u]) {
                    if (deg[v] == 1) continue;
                    cout << deg[v] << ' ' << deg[u] - 1 << '\n';
                    break;
                }
                break;
            }
        }
    }
    return 0;
}
