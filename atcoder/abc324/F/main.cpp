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

#define debugMap(mp) cout << "map: \n"; for (auto &kv : mp) cout << kv.first << ' ' << kv.second << '\n'; cout << "-----" << endl;
#define debugStack(st) cout << "stack: "; while (st.size()) { cout << st.top() << ' '; st.pop(); } cout << '\n';

double EPS = 1e-9;
int INF = 0x3f3f3f3f;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};
// const int mod = 998244353;
int d4[5] = { 0, 1, 0, -1, 0 };

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;


void solve() {
    int n, m; cin >> n >> m;
    vector<vector<vector<int>>> g(n + 1);
    rep(i, m) {
        int u, v, b, c;
        cin >> u >> v >> b >> c;
        g[u].push_back({ v, b, c });
    }

    auto score = [&](int x, int y) -> double {
        if (y == 0) return 0;
        return (double)x / (double)y;
    };
    vector<vector<int>> memo(n + 1);
    function<vector<int>(int)> dfs = [&](int x) -> vector<int> { // found, b, c
        if (x == n) return { 1, 0, 0 };
        if (memo[x].size()) return memo[x];
        int res_b = 0, res_c = 1;
        int isFound = false;
        for (auto &h : g[x]) {
            auto y = h[0], b = h[1], c = h[2];
            auto arr = dfs(y);
            auto found = arr[0], sum_b = arr[1], sum_c = arr[2];
            if (!found) continue;
            isFound = true;
            if (score(sum_b + b, sum_c + c) > score(res_b, res_c)) {
                res_b = sum_b + b;
                res_c = sum_c + c;
            }
        }
        vector<int> res;
        if (isFound) {
            res = { 1, res_b, res_c };
        } else {
            res = { 0, 0, 0 };
        }

        memo[x] = res;
        return res;
    };
    auto h = dfs(1);
    double ans = score(h[1], h[2]);
    cout << fixed << setprecision(11) << ans;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
