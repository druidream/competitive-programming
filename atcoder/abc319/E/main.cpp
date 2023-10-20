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
    ll n, x, y; cin >> n >> x >> y;
    vector<pair<ll, ll>> pt(n - 1);
    ll u = 1;
    rep(i, n - 1) {
        ll p, t; cin >> p >> t;
        pt[i] = { p, t };
        u = lcm(u, p);
    }
    // print(u)
    map<ll, ll> mp;
    for (ll v = 0; v < u; v++) {
        ll cur = v;
        for (int i = 0; i < n - 1; i++) {
            if (cur % pt[i].first == 0) cur += pt[i].second;
            else {
                cur += pt[i].first - cur % pt[i].first + pt[i].second;
            }
        }
        // cout << v << ' ' << cur << endl;
        mp[v] = cur - v;
    }
    int q; cin >> q;
    rep(i, q) {
        ll v; cin >> v;
        ll r = (v + x) % u;
        // cout << r << ' ' << mp[r] << endl;
        ll ans = v + mp[r] + y + x;
        print(ans)
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
