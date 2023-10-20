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

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;

void solve() {
    int n, k; cin >> n >> k;
    vll c(n); rep(i, n) cin >> c[i];
    vi p(k); rep(i, k) cin >> p[i];
    vector<vector<int>> e(n);
    rep(i, n) {
        int m; cin >> m;
        rep(j, m) {
            int x; cin >> x;
            e[i].push_back(x - 1);
        }
    }
    vll memo(n, -1);
    // printInline(c)
    // printInline(p)
    rep(i, k) {
        memo[p[i] - 1] = 0;
    }
    // printInline(memo)
    function<int(int)> dfs = [&](int x) -> int {
        if (memo[x] != -1) return memo[x];
        ll res = c[x];
        if (e[x].size() != 0) {
            ll sum = 0;
            for (auto &y : e[x]) {
                sum += dfs(y);
            }
            res = min(res, sum);
        }
        memo[x] = res;
        return memo[x];
    };
    rep(i, n) {
        dfs(i);
    }
    printInline(memo)
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
        // print(T)
        solve();
    return 0;
}
