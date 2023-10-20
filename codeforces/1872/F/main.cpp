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
    vll a(n); 
    rep(i, n) {
        ll x; cin >> x;
        a[i] = x - 1;
    }
    vll c(n); rep(i, n) cin >> c[i];
    vector<vector<ll>> g(n);
    vector<ll> deg(n);
    rep(i, n) {
        ll v = a[i];
        g[i].push_back(v);
        deg[v]++;
    }
    vector<int> vis(n);
    queue<ll> q;
    rep(i, n) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }
    // printInline(a)
    vi res;
    while (!q.empty()) {
        ll x = q.front(); q.pop();
        vis[x] = 1;
        // print(x)
        // ans += c[x] * 2;
        res.push_back(x + 1);
        ll y = a[x];
        deg[y]--;
        if (deg[y] == 0) {
            q.push(y);
        }
    }
    rep(i, n) {
        if (vis[i]) continue;
        vll arr;
        ll x = i;
        while (!vis[x]) {
            arr.push_back(x);
            vis[x] = 1;
            x = a[x];
        }
        // printInline(arr)
        int m = arr.size();
        ll mnval = 1e9 + 1, mnidx = -1;
        for (int j = 0; j < m; j++) {
            int idx = arr[j];
            if (c[idx] < mnval) {
                mnidx = j;
                mnval = c[idx];
            }
        }
        // print(mnidx)
        for (int i = 0; i < m; i++) {
            int idx = (mnidx + i + 1) % m;
            res.push_back(arr[idx] + 1);
        }
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
        solve();
    return 0;
}
