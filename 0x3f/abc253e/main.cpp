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
    int n, m, k; cin >> n >> m >> k;
    // int memo[n][m + 1];
    // memset(memo, -1, sizeof(memo));
    vector<vector<int>> memo(n, vector<int>(m + 1, -1));
    function<int(int, int)> dfs = [&](int i, int x) -> int {
        if (i == n - 1) return 1;
        if (memo[i][x] != -1) return memo[i][x];
        int res = 0;
        for (int y = 1; y <= m; y++) {
            if (abs(y - x) < k) continue;
            res = (res + dfs(i + 1, y)) % mod;
        }
        memo[i][x] = res;
        return res;
    };
    int ans = 0;
    for (int x = 1; x <= m; x++) {
        ans = (ans + dfs(0, x)) % mod;
    }
    print((ans + mod) % mod)
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
