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
    //    #ifndef ONLINE_JUDGE
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    //    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vi mx(2, 1), mn(2, 0), f(2, 1), g(2, 0);
        int cnt = 1;
        rep(i, n) {
            char symbol; cin >> symbol;
            if (symbol == '+') {
                int p, v; cin >> p >> v;
                cnt++;
                int u = cnt;
                if (f[p] > 0) {
                    f[u] = f[p] + v;
                } else {
                    f[u] = v;
                }
                if (g[p] < 0) {
                    g[u] = g[p] + v;
                } else {
                    g[u] = v;
                }
                int a = max(mx[p], f[u]);
                int b = min(mn[p], g[u]);
                mx.push_back(a);
                mn.push_back(b);
            } else {
//                printInline(mx)
//                printInline(mn)
                int u, v, k; cin >> u >> v >> k;
                bool ans = k >= mn[v] && k <= mx[v];
                printBool(ans)
            }
        }
    }
    return 0;
}
