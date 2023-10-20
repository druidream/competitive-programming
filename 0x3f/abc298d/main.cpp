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
    queue<int> q;
    q.push(1);
    ll ans = 1;
    function<ll(ll, ll)> powMod = [&](ll x, ll p) -> ll {
        if (p == 0) return 1;
        if (p == 1) return x;
        ll v = powMod(x, p / 2);
        v = (v * v) % mod;
        if (p % 2) v = (v * x) % mod;
        return v;
    };
    ll inv10 = powMod(10, mod - 2);
    ll pow10 = 1;
    rep(i, n) {
        int t; cin >> t;
        if (t == 1) {
            ll x; cin >> x;
            q.push(x);
            ans = (ans * 10 + x) % mod;
            pow10 = pow10 * 10 % mod;
        } else if (t == 2) {
            ll x = q.front(); q.pop();
            // ll v = powMod(10, q.size());
            ans = (ans - x * pow10) % mod;
            pow10 = pow10 * inv10 % mod;
        } else {
            print((ans + mod) % mod)
        }
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
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
