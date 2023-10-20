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

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> g(n + 1);
    rep(i, m) {
        int a, b, d; cin >> a >> b >> d;
        g[a].push_back({ b, d });
        g[b].push_back({ a, -d });
    }
    queue<int> qu;
    vector<int> vis(n + 1);
    vector<ll> f(n + 1, INFF);
    bool ans = true;
    for (int i = 1; i <= n; i++) {
        if (!ans) break;
        if (vis[i]) continue;
        vis[i] = 1;
        f[i] = 0;
        qu.push(i);
        while (!qu.empty()) {
            int x = qu.front(); qu.pop();
            vis[x] = 1;
            for (auto &p : g[x]) {
                ll y = p.first, w = p.second;
                // cout << x << ' ' << f[x] << ' ' << y << ' ' << f[y] << endl;
                if (vis[y]) continue;
                // if (vis[y]) {
                //     if (f[y] + w != f[x]) {
                //         // cout << x << ' ' << f[x] << ' ' << y << ' ' << f[y] << endl;
                //         ans = false;
                //         break;
                //     }
                //     continue;
                // }
                if (f[y] == INFF) {
                    f[y] = f[x] + w;
                    qu.push(y);
                } else if (f[y] != f[x] + w) {
                    
                    // printInline(f)
                    ans = false;
                    break;
                }
            }
        }
    }
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
