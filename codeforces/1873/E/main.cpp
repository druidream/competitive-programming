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
    ll n, x; cin >> n >> x;
    vll a(n); rep(i, n) cin >> a[i];
    auto check = [&](ll v) -> bool {
        ll tot = 0;
        rep(i, n) {
            if (a[i] > v) continue;
            tot += v - a[i];
        }
        return tot <= x;
    };
    ll lo = 1, hi = 1e18;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (check(mid)) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    print(hi)
}

void solve1() {
    ll n, x; cin >> n >> x;
    vll a(n); rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    ll h = a[0];
    ll cnt = 1;
    for (int i = 1; i < n; i++) {
        ll diff = a[i] - a[i - 1];
        if (x >= diff * i) {
            // cout << i << ' ' << h << ' ' << x << ' ' << cnt << endl;
            h = a[i];
            x -= diff * i;
            cnt++;
        } else {
            break;
        }
    }
    h += x / cnt;
    print(h)
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
        solve1();
    return 0;
}
