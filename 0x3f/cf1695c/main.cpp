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
const int mod = 998244353;
int d4[5] = { 0, 1, 0, -1, 0 };

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    rep(i, n) {
        rep(j, m) {
            cin >> a[i][j];
        }
    }
    if ((n + m - 1) % 2 == 1) {
        print("NO")
        return;
    }
    vector<vector<int>> f(n, vector<int>(m, -1e9));
    vector<vector<int>> g(n, vector<int>(m, 1e9));
    f[0][0] = a[0][0];
    g[0][0] = a[0][0];
    rep(i, n) {
        rep(j, m) {
            if (i == 0 && j == 0) continue;
            if (i > 0) f[i][j] = max(f[i][j], f[i - 1][j]);
            if (j > 0) f[i][j] = max(f[i][j], f[i][j - 1]);
            f[i][j] += a[i][j];
        }
    }
    rep(i, n) {
        rep(j, m) {
            if (i == 0 && j == 0) continue;
            if (i > 0) g[i][j] = min(g[i][j], g[i - 1][j]);
            if (j > 0) g[i][j] = min(g[i][j], g[i][j - 1]);
            g[i][j] += a[i][j];
        }
    }
    // for (auto line : f) {
    //     printInline(line)
    // }
    // for (auto line : g) {
    //     printInline(line)
    // }
    bool ans = f[n - 1][m - 1] >= 0 && g[n - 1][m - 1] <= 0;
    printBool(ans)
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
