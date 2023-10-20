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
    int n; cin >> n;
    vi a(n); rep(i, n) cin >> a[i];
    vector<vector<int>> f(31, vector<int>(n, 0));
    rep(j, 31) {
        int len = 0;
        for (int i = n - 1; i >= 0; i--) {
            if ((a[i] >> j) & 1) {
                len++;
                f[j][i] = len;
            } else {
                len = 0;
            }
        }
    }
    int q; cin >> q;
    vi res(q, -1);
    rep(i, q) {
        int l, k; cin >> l >> k;
        l--;
        if (a[l] < k) {
            continue;
        }
        int u = a[l];
        int len = -1, len1 = n;
        for (int j = 30; j >= 0; j--) {
            if ((1 << j) > k) {
                len = max(len, f[j][l]);
                if ((u >> j) & 1) u ^= 1 << j;
            } else {
                if (u < k) {
                    break;
                } else if (u == k) {

                } else {

                }
            }
        }
        for (int j = 0; j < 31; j++) {
            if ((u >> j) & 1) {
                len1 = min(len1, f[j][l]);
            }
        }
        int r = max(l + len - 1, l + len1 - 1);
        // cout << i << ' ' << a[l] << ' ' << k << ' ' << u << ' ' << len << ' ' << len1 << endl;
        res[i] = r + 1;
    }
    printInline(res)
}

// TLE
void solve1() {
    int n; cin >> n;
    vi a(n); rep(i, n) cin >> a[i];
    int q; cin >> q;
    vi res(q, -1);
    rep(i, q) {
        int l, k; cin >> l >> k;
        l--;
        if (a[l] < k) continue;
        int cur = a[l], r = l;
        for (int j = l + 1; j < n; j++) {
            cur &= a[j];
            if (cur >= k) r = j;
        }
        res[i] = r + 1;
    }
    printInline(res)
}

void solve2() {
    int n; cin >> n;
    vi a(n); rep(i, n) cin >> a[i];
    vector<vector<int>> f(n + 1, vector<int>(31));
    rep(i, n) {
        rep(j, 31) {
            f[i + 1][j] = f[i][j] + ((a[i] >> j) & 1);
        }
    }
    int q; cin >> q;
    vi res(q, -1);
    rep(i, q) {
        int l, k; cin >> l >> k;
        l--;
        if (a[l] < k) continue;
        int lo = l, hi = n - 1;
        auto check = [&](int x) -> bool {
            int cur = 0;
            rep(j, 31) {
                if (f[x + 1][j] - f[l][j] == x - l + 1) {
                    cur |= 1 << j;
                }
            }
            return cur >= k;
        };
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (check(mid)) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        res[i] = hi + 1;
    }
    printInline(res)
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
        solve2();
    return 0;
}
