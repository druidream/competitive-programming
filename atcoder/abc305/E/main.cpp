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

// TLE
// void solve() {
//     int n, m, k; cin >> n >> m >> k;
//     vector<vector<int>> g(n);
//     rep(i, m) {
//         int a, b; cin >> a >> b;
//         a--; b--;
//         g[a].push_back(b);
//         g[b].push_back(a);
//     }
//     vector<pair<int, int>> guards(k);
//     rep(i, k) {
//         int p, h; cin >> p >> h;
//         p--;
//         guards[i] = { h, p };
//     }
//     sort(guards.begin(), guards.end(), greater());
//     vector<int> dis(n, -1);
//     function<void(int, int, int)> dfs = [&](int x, int h, int pa) {
//         if (h < 0) return;
//         // cout << "dfs: " << ' ' << x << ' ' << h << ' ' << pa << endl;
//         dis[x] = h;
//         for (auto &y : g[x]) {
//             if (y == pa) continue;
//             if (h > dis[y]) {
//                 dfs(y, h - 1, x);
//             }
//         }
//     };
//     rep(i, k) {
//         auto [h, p] = guards[i];
//         // cout << h << ' ' << p << endl;
//         if (h > dis[p]) {
//             dfs(p, h, -1);
//         }
//     }
//     vector<int> res;
//     rep(i, n) {
//         if (dis[i] != -1) {
//             res.push_back(i + 1);
//         }
//     }
//     // printInline(dis)
//     print(res.size())
//     printInline(res)
// }

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> g(n);
    rep(i, m) {
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<pair<int, int>> guards(k);
    vector<int> dis(n, -1);
    rep(i, k) {
        int p, h; cin >> p >> h;
        p--;
        guards[i] = { h, p };
        dis[p] = max(dis[p], h);
    }
    queue<pair<int, int>> q;
    rep(i, n) {
        if (dis[i] > 0) q.push({ i, dis[i] });
    }
    while (!q.empty()) {
        auto [x, h] = q.front(); q.pop();
        for (auto &y : g[x]) {
            if (dis[y] < h - 1) {
                dis[y] = h - 1;
                q.push({ y, h - 1 });
            }
        }
    }
    vector<int> res;
    rep(i, n) {
        if (dis[i] != -1) {
            res.push_back(i + 1);
        }
    }
    // printInline(dis)
    print(res.size())
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
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
