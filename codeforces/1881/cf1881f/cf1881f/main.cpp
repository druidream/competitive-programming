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
//double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};
// const int mod = 998244353;
int d4[5] = { 0, 1, 0, -1, 0 };

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;

void solve() {
    int n, k; cin >> n >> k;
    set<int> st;
    rep(i, k) {
        int v; cin >> v;
        v--;
        st.insert(v);
    }
    vector<vector<int>> g(n, vector<int>());
    rep(i, n) {
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int dis0 = 0;
    vi cnt(n);
    function<int(int, int, int)> dfs = [&](int x, int d, int p) -> int {
        int v = 0;
        if (st.count(x)) {
            dis0 = max(dis0, d);
            v++;
        }
        for (auto &y : g[x]) {
            if (y == p) continue;
            v += dfs(y, d + 1, x);
        }
        cnt[x] = v;
        return v;
    };
    dfs(0, 0, -1);
    printInline(cnt)
    vi res(n);
    // function<void(int)> reroot = [&](int x, int p, int su) -> int {

    // };
    // int ans = *min_element(res.begin(), res.end());
    // print(ans)
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
