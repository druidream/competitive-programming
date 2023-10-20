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
    vll a(n); rep(i, n) cin >> a[i];
    vll f(n + 1), g(n + 1, 0);
    for (int i = 0; i < n; i++) {
        f[a[i]]++;
    }
    ll ans = 0, cnt = 0;
    auto helper = [&](ll x) -> ll {
        if (x <= 2) return 0;
        ll cnt = 0;
        for (ll i = 1; i < x - 1; i++) {
            cnt += i * (x - i - 1);
        }
        return cnt;
    };
    for (int i = 1; i <= n; i++) {
        ll x = helper(f[i]);
        ans -= x;
    }
    f[a[0]]--;
    // printInline(f)
    // print(ans)
    for (int i = 1; i < n; i++) {
        ll left = a[i - 1], cur = a[i];
        ll before = f[left] * g[left];
        ll before1 = f[cur] * g[cur];
        f[cur]--;
        g[left]++;
        ll after = f[left] * g[left];
        ll after1 = f[cur] * g[cur];
        // printInline(f)
        // printInline(g)
        cnt += after - before;
        if (left != cur) cnt += after1 - before1;
        // cnt += after1 - before1;
        ans += cnt;
        // if (left == cur) ans -= after;
        // printInline(f)
        // printInline(g)
        // cout << left << ' ' << cur << ' ' << before << ' ' << after << ' ' << before1 << ' ' << after1 << endl;
        // cout << "a[i]: " << a[i] << ' ' << i << ' ' << cnt << ' ' << ans << endl;
    }
    // printInline(f)
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
