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

double EPS = 1e-9;
int INF = 0x3f3f3f3f;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};
const int mod = 998244353;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;

void solve() {
    int n; cin >> n;
    vll a(n); rep(i, n - 1) cin >> a[i + 1];
    vi f(n + 1, 0);
    ll extra = 0;
    bool ans = true;
    Rep(i, 1, n) {
        ll v = a[i] - a[i - 1];
        if (v > n) {
            extra = v;
            continue;
        }
        if (v <= n && f[v] == 1) {
            extra = v;
            continue;
        }
        f[v] = 1;
    }
    // printInline(f)
    // print(extra)
    vi arr;
    rep(i, n) {
        if (f[i + 1] == 0) {
            arr.push_back(i + 1);
        }
    }
    if (arr.size() > 2) ans = false;
    if (arr.size() == 2 && arr[0] + arr[1] != extra) {
        ans = false;
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
        // print(T)
        solve();
    return 0;
}
