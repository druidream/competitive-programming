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

    ll mod = 1e9 + 7;
    int n, k; cin >> n >> k;
    // vector<int> f(n + 1, 0);
    // f[1] = 1;
    // for (int i = 0; i < k; i++) {
    //     for (int j = n; j > 0; j--) {
    //         for (int v = j * 2; v <= n; v += j) {
    //             f[v] = (f[v] + f[j]) % mod;
    //         }
    //     }
    // }
    // ll ans = 0;
    // for (auto &v : f) {
    //     ans = (ans + v) % mod;
    // }
    // print(ans)

    vector<vector<int>> memo(k + 1, vector<int>(n + 1, 0));
    function<int(int, int)> dfs = [&](int i, int u) -> int {
        if (i == 0) return 1;
        if (memo[i][u]) return memo[i][u];
        ll res = 0;
        for (int v = u; v <= n; v += u) {
            res = (res + dfs(i - 1, v)) % mod;
        }
        return memo[i][u] = res;
    };
    ll ans = dfs(k, 1);
    print(ans)

    return 0;
}
