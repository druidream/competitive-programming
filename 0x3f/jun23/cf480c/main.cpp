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
int mod = 1e9 + 7;

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
    int n, a, b, k; cin >> n >> a >> b >> k;
    vector<vector<int>> memo(n + 1, vector<int>(k, -1));
    function<int(int, int)> dfs = [&](int x, int cur) -> int {
        if (cur == k) {
            return 1;
        }
        if (memo[x][cur] >= 0) return memo[x][cur];
        int d = abs(x - b);
        ll cnt = 0;
        for (int t = 1; t < d; t++) {
            if (x - t >= 1) {
                cnt = (cnt + dfs(x - t, cur + 1)) % mod;
            }
            if (x + t <= n) {
                cnt = (cnt + dfs(x + t, cur + 1)) % mod;
            }
        }
        return memo[x][cur] = cnt;
    };
    int ans = dfs(a, 0);
    print(ans);
    return 0;
}
