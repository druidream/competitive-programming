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
    int n, k, a, b; cin >> n >> k >> a >> b;
    a--; b--;
    vector<pair<ll, ll>> xy(n);
    rep(i, n) {
        ll x, y; cin >> x >> y;
        xy[i] = { x, y };
    }
    ll sx = xy[a].first, sy = xy[a].second;
    ll ex = xy[b].first, ey = xy[b].second;
    ll ans = abs(sx - ex) + abs(sy - ey);
    if (k > 1) {
        vector<pair<ll, int>> f(k), g(k);
        rep(i, k) {
            ll x = xy[i].first, y = xy[i].second;
            f[i] = { abs(x - sx) + abs(y - sy), i };
            g[i] = { abs(x - ex) + abs(y - ey), i };
        }
        sort(f.begin(), f.end());
        sort(g.begin(), g.end());
        if (f[0].second != g[0].second) {
            ans = min(ans, f[0].first + g[0].first);
        } else {
            ans = min(ans, f[0].first + g[1].first);
            ans = min(ans, f[1].first + g[0].first);
        }
    }
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
    cin >> T;
    while (T--)
        solve();
    return 0;
}
