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
const int mod = 998244353;
int d4[5] = { 0, 1, 0, -1, 0 };

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;

void solve() {
    int n, m; cin >> n >> m;
    vll h(n + 1); rep(i, n) cin >> h[i + 1];
    vector<vector<int>> g(n + 1);
    rep(i, m) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int q; cin >> q;
    while (q--) {
        int a, b, e; cin >> a >> b >> e;
        vll dis(n + 1, -1);
        function<bool(int, ll)> dfs = [&](int x, ll u) -> bool {
            if (x == b) return true;
            bool res = false;
            for (auto &y : g[x]) {
                ll v = u - h[y] + h[x];
                if (v < 0) continue;
                if (v > dis[y]) {
                    dis[y] = v;
                    if (dfs(y, v)) res = true;
                }
            }
            return res;
        };
        dis[a] = e;
        bool ans = dfs(a, e);
        printBool(ans)
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
