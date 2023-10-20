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
    vector<vector<ll>> g(n, vector<ll>(n));
    rep(i, n - 1) {
        for (int j = i; j < n - 1; j++) {
            int x; cin >> x;
            // cout << x << ' ' << i << ' ' << j << endl;
            g[i][j + 1] = x;

        }
    }
    // rep(i, n) {
    //     auto a = g[i];
    //     printInline(a)
    // }
    // print(g[0][1])
    vll memo(1 << n, -1);
    function<ll(int)> dfs = [&](int x) -> ll {
        vi bits;
        for (int i = 0; i < 31; i++) {
            if ((x >> i) & 1) bits.push_back(i);
        }
        // printInline(bits)
        if (bits.size() <= 1) return 0;
        if (memo[x] != -1) return memo[x];
        ll res = 0;
        for (int i = 0; i < bits.size(); i++) {
            for (int j = i + 1; j < bits.size(); j++) {
                int y = x;
                y ^= 1 << bits[i];
                y ^= 1 << bits[j];
                // cout << bits[i] << ' ' << bits[j] << ' ' << g[bits[i]][bits[j]] << endl;
                // print(g[bits[i]][bits[j]])
                res = max(res, dfs(y) + g[bits[i]][bits[j]]);
            }
        }
        // printInline(bits)
        // print(res)
        memo[x] = res;
        return res;
    };
    ll ans = dfs((1 << n) - 1);
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
        solve();
    return 0;
}
