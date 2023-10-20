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

bool check(vector<string> g, int tot) {
    int n = g.size(), m = g[0].size();
    // rep(i, n) {
    //     print(g[i])
    // }
    function<int(int, int)> dfs = [&](int i, int j) -> int {
        int res = 0;
        rep(k, 4) {
            int x = i + d4[k], y = j + d4[k + 1];
            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == '#') {
                g[x][y] = '.';
                res += 1 + dfs(x, y);
            }
        }
        return res;
    };
    rep(i, n) {
        rep(j, m) {
            if (g[i][j] == '.') continue;
            int cnt = dfs(i, j);
            // cout << i << ' ' << j << ' ' << cnt << ' ' << tot << endl;
            return cnt != tot;
        }
    }
    return false;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<string> g(n);
    rep(i, n) cin >> g[i];
    int tot = 0;
    rep(i, n) {
        rep(j, m) {
            tot += g[i][j] == '#';
        }
    }
    if (tot < 3) {
        print(-1)
        return;
    }

    bool disconnectByOne = false;
    rep(i, n) {
        if (disconnectByOne) break;
        rep(j, m) {
            if (g[i][j] == '.') continue;
            auto h = g;
            h[i][j] = '.';
            disconnectByOne = check(h, tot - 1);
            if (disconnectByOne) {
                // cout << i << ' ' << j << ' ' << disconnectByOne << endl;
                break;
            }
        }
    }
    int ans = disconnectByOne ? 1 : 2;
    print(ans)
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
        // print(T)
        solve();
    return 0;
}

/*
10 10
..........
..........
..........
..........
...###....
...#.#....
...#####..
.....#.#..
.....###..
..........
*/
