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
    int mx = max(m, n);
    vector<vector<int>> f(1, vector<int>(1, 0));
    int offset = 0;
    while (f.size() < mx) {
        int sz = f.size();
        vector<vector<int>> g(sz * 2, vector<int>(sz * 2, 0));
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                g[i][j] = f[i][j];
                g[i][j] |= 0 << offset;
            }
        }
        for (int i = 0; i < sz; i++) {
            for (int j = sz; j < sz * 2; j++) {
                g[i][j] = f[i][j - sz];
                g[i][j] |= 1 << offset;
            }
        }
        for (int i = sz; i < sz * 2; i++) {
            for (int j = 0; j < sz; j++) {
                g[i][j] = f[i - sz][j];
                g[i][j] |= 2 << offset;
            }
        }
        for (int i = sz; i < sz * 2; i++) {
            for (int j = sz; j < sz * 2; j++) {
                g[i][j] = f[i - sz][j - sz];
                g[i][j] |= 3 << offset;
            }
        }
        offset += 2;
        f = g;
    }
    vector<vector<int>> res(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = f[i][j];
        }
    }
    print(n * m)
    rep(i, n) {
        auto line = res[i];
        printInline(line)
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
