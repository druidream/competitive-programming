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
    vector<string> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    int ans = 0;
    auto f = [&](char c, int group) -> int {
        int ans = 4 * group;
        if (c == 'A') ans += 0;
        if (c == 'C') ans += 1;
        if (c == 'G') ans += 2;
        if (c == 'T') ans += 3;
        return ans;
    };
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                set<int> seen;
                for (int r = 0; r < n; r++) {
                    int mask = 0;
                    mask |= 1 << f(a[r][i], 0);
                    mask |= 1 << f(a[r][j], 1);
                    mask |= 1 << f(a[r][k], 2);
                    seen.insert(mask);
                }
                bool ok = true;
                for (int r = 0; r < n; r++) {
                    if (!ok) break;
                    int mask = 0;
                    mask |= 1 << f(b[r][i], 0);
                    mask |= 1 << f(b[r][j], 1);
                    mask |= 1 << f(b[r][k], 2);
                    if (seen.count(mask)) ok = false;
                }
                if (ok) ans++;
            }
        }
    }
    print(ans)
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
