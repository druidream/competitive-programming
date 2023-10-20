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
    int n, T; cin >> n >> T;
    string s; cin >> s;
    vector<vector<int>> a(n);
    rep(i, n) {
        int t, x, y; cin >> t >> x >> y;
        a[i] = { t, x, y };
    }
    sort(a.begin(), a.end());
    auto check = [&](int x) -> vector<int> { // ok, mx, mn
        string cur = string(n, '0');
        rep(i, n) {
            if (a[i][1] == x || a[i][2] == x) {

            }
        }
    };
    int cnt = 0, mx = 0, mn = INT_MAX;
    for (int i = 1; i <= n; i++) {
        auto arr = check(i);
        if (arr[0]) {
            cnt++;
            mx = max(mx, arr[1]);
            mn = min(mn, arr[2]);
        }
    }
    string mx_str = (mx == INT_MAX) ? "Infinity" : mx;
    cout << cnt << ' ' << mn << ' ' << mx_str << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
