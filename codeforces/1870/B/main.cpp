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
    vi a(n); rep(i, n) cin >> a[i];
    vi b(m); rep(i, m) cin >> b[i];
    int cur = 0;
    rep(i, n) {
        cur ^= a[i];
    }
    int mx = cur, mn = cur;
    if (n % 2) {
        int u = cur;
        rep(i, m) {
            rep(j, 32) {
                if ((b[i] >> j) & 1) {
                    u |= (1 << j);
                }
            }
        }
        cout << mn << ' ' << u << "\n";
    } else {
        int u = cur;
        rep(i, m) {
            rep(j, 32) {
                if (((u >> j) & 1) == 0) continue;
                if ((b[i] >> j) & 1) {
                    u ^= (1 << j);
                }
            }
        }
        cout << u << ' ' << mx << "\n";
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
