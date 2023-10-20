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
    int n, a, b; cin >> n >> a >> b;
    a--; b--;
    vector<vector<int>> g(n, vector<int>());
    vi deg(n, 0);
    rep(i, n) {
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    if (a == b) {
        print("NO")
        return;
    }
    int leafCnt = 0;
    rep(i, n) {
        if (deg[i] == 1) leafCnt++;
    }
    if (leafCnt == 0) {
        print("YES")
        return;
    }
    int p = 0;
    auto findB = [&]() -> int {
        queue<int> q;
        rep(i, n) {
            if (deg[i] == 1) q.push(i);
        }
        auto d = deg;
        bool foundB = false;
        vi vis(n, 0);
        while (!q.empty()) {
            auto x = q.front(); q.pop();
            vis[x] = 1;
            if (x == b) {
                foundB = true;
                continue;
            }
            for (auto &y : g[x]) {
                if (vis[y]) continue;
                d[y]--;
                if (d[y] == 1) q.push(y);
            }
        }

        if (foundB) {
            q.push(b);
            int len = 0;
            while (!q.empty()) {
                auto x = q.front(); q.pop();
                len++;
                vis[x] = 1;
                if (x == a) {
                    return -2;
                }
                for (auto &y : g[x]) {
                    if (vis[y]) continue;
                    d[y]--;
                    if (d[y] == 1) {
                        q.push(y);
                    } else {
                        // find cycle
                        p = y;
                        return len;
                    }
                }
            }
        }
        return -1;
    };
    auto findP = [&]() -> int {
        queue<int> q;
        q.push(a);
        int ans = 0;
        vi vis(n, 0);
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto x = q.front(); q.pop();
                vis[x] = 1;
                if (x == p) {
                    return ans;
                }
                for (auto &y : g[x]) {
                    if (vis[y]) continue;
                    q.push(y);
                }
            }
            ans++;
        }
        return ans;
    };
    bool ans = false;
    int disB = findB();
    // cout << disB << endl;
    if (disB == -2) {
        ans = false; // a is closer to the cycle than b
    } else if (disB == -1) {
        ans = true; // already in cycle
    } else {
        int disA = findP();
        ans = disB < disA;
        // cout << disA <<  endl;
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
