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
    string s; cin >> s;
    vector<vector<ll>> f(n, vector<ll>(3)), g(n, vector<ll>(3));
    rep(i, n) {
        if (i > 0) f[i] = f[i - 1];
        if (s[i] != 'M') continue;
        f[i][a[i]]++;
    }
    rev(i, n) {
        if (i < n - 1) g[i] = g[i + 1];
        if (s[i] != 'X') continue;
        g[i][a[i]]++;
    }
    // rep(i, n) {
    //     auto x = f[i], y = g[i];
    //     printInline(x)
    //     printInline(y)
    // }
    ll ans = 0;
    rep(i, n) {
        if (s[i] != 'E') continue;
        if (a[i] == 0) {
            ans += f[i][0] * g[i][0] * 1;
            ans += f[i][0] * g[i][1] * 2;
            ans += f[i][0] * g[i][2] * 1;
            ans += f[i][1] * g[i][0] * 2;
            ans += f[i][1] * g[i][1] * 2;
            ans += f[i][1] * g[i][2] * 3;
            ans += f[i][2] * g[i][0] * 1;
            ans += f[i][2] * g[i][1] * 3;
            ans += f[i][2] * g[i][2] * 1;
        } else if (a[i] == 1) {
            ans += f[i][0] * g[i][0] * 2;
            ans += f[i][0] * g[i][1] * 2;
            ans += f[i][0] * g[i][2] * 3;
            ans += f[i][1] * g[i][0] * 2;
            ans += f[i][1] * g[i][1] * 0;
            ans += f[i][1] * g[i][2] * 0;
            ans += f[i][2] * g[i][0] * 3;
            ans += f[i][2] * g[i][1] * 0;
            ans += f[i][2] * g[i][2] * 0;
        } else if (a[i] == 2) {
            ans += f[i][0] * g[i][0] * 1;
            ans += f[i][0] * g[i][1] * 3;
            ans += f[i][0] * g[i][2] * 1;
            ans += f[i][1] * g[i][0] * 3;
            ans += f[i][1] * g[i][1] * 0;
            ans += f[i][1] * g[i][2] * 0;
            ans += f[i][2] * g[i][0] * 1;
            ans += f[i][2] * g[i][1] * 0;
            ans += f[i][2] * g[i][2] * 0;
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
    // cin >> T;
    while (T--)
        solve();
    return 0;
}