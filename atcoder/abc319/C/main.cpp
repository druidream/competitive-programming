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
    vi a(9); rep(i, 9) cin >> a[i];
    function<int(int, int)> dfs = [&](int cur, int mask) -> int {
        if (cur == 9) return 0;
        int res = 0;
        for (int i = 0; i < 9; i++) {
            bool ok = true;
            if (((mask >> i) & 1) == 0) continue;
            int j = (i + 3) % 9, k = (i + 6) % 9;
            if ((mask >> k) & 1 && ((mask >> j) & 1) == 0 && a[j] == a[i]) ok = false;
            if ((mask >> j) & 1 && ((mask >> k) & 1) == 0 && a[k] == a[i]) ok = false;
            if (ok) {
                j = (i + 1) % 3 + i / 3 * 3;
                k = (i + 2) % 3 + i / 3 * 3;
                if ((mask >> k) & 1 && ((mask >> j) & 1) == 0 && a[j] == a[i]) ok = false;
                if ((mask >> j) & 1 && ((mask >> k) & 1) == 0 && a[k] == a[i]) ok = false;
            }
            if (ok && (i == 0 || i == 4 || i == 8)) {
                if (i == 0) { j = 4; k = 8; }
                if (i == 4) { j = 0; k = 8; }
                if (i == 8) { j = 0; k = 4; }
                // j = (i + 4) % 12;
                // k = (i + 8) % 12;
                if ((mask >> k) & 1 && ((mask >> j) & 1) == 0 && a[j] == a[i]) ok = false;
                if ((mask >> j) & 1 && ((mask >> k) & 1) == 0 && a[k] == a[i]) ok = false;
            }
            if (ok && (i == 2 || i == 4 || i == 6)) {
                // j = (i + 2) % 6 + 2;
                // k = (i + 4) % 6 + 2;
                if (i == 2) { j = 4; k = 6; }
                if (i == 4) { j = 2; k = 6; }
                if (i == 6) { j = 2; k = 4; }
                if ((mask >> k) & 1 && ((mask >> j) & 1) == 0 && a[j] == a[i]) ok = false;
                if ((mask >> j) & 1 && ((mask >> k) & 1) == 0 && a[k] == a[i]) ok = false;
            }
            if (ok) {
                res += dfs(cur + 1, mask ^ (1 << i));
            } else {
                int x = 1;
                for (int j = cur + 1; j < 9; j++) {
                    x *= 9 - j;
                }
                res += x;
            }
        }
        return res;
    };
    int cnt = dfs(0, (1 << 9) - 1);
    int tot = 1;
    for (int i = 1; i <= 9; i++) {
        tot *= i;
    }
    // print(cnt)
    // print(tot)
    long double ans = 1 - (long double)cnt / (long double)tot;
    cout << setprecision(8) << ans << endl;
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
