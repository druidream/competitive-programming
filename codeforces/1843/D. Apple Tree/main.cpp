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
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<vector<int>> g(n + 1, vector<int>());
        rep(i, n - 1) {
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<ll> cnt(n + 1);
        function<int(int, int)> dfs = [&](int x, int p) -> int {
            if (x != 1 && g[x].size() == 1) {
                cnt[x] = 1;
                return 1;
            }
            int res = 0;
            for (auto &y : g[x]) {
                if (y == p) continue;
                res += dfs(y, x);
            }
            cnt[x] = res;
            return res;
        };
        dfs(1, 0);
        // printInline(cnt)
        int q; cin >> q;
        rep(i, q) {
            int x, y; cin >> x >> y;
            ll ans = cnt[x] * cnt[y];
            print(ans)
        }
    }
    return 0;
}
