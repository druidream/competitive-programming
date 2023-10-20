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

double EPS = 1e-9;
int INF = 0x3f3f3f3f;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<vector<pair<int, int>>> g(n + 1); // nxt, idx
        rep(i, n - 1) {
            int u, v; cin >> u >> v;
            g[u].push_back({ v, i });
            g[v].push_back({ u, i });
        }
        int ans = 0;
        function<void(int, int, int, int)> dfs = [&](int x, int p, int pidx, int reading) {
            ans = max(ans, reading);
            for (int i = 0; i < g[x].size(); i++) {
                int y = g[x][i].first, idx = g[x][i].second;
                if (y == p) continue;
                if (idx < pidx) {
                    dfs(y, x, idx, reading + 1);
                } else {
                    dfs(y, x, idx, reading);
                }
            }
        };
        dfs(1, -1, -1, 1);
        print(ans)
    }
    return 0;
}
