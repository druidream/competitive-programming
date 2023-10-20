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

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    vi c(n);
    function<int(int, int)> f = [&](int x, int y) -> int {
        if (x == 0) return 0;
        if (y == 0) return 1;
        if (x == y) return 2;
        if (x >= y * 2) {
            int cnt = x / (y + y);
            return cnt * 3 + f(x - y * cnt * 2, y);
        } else {
            return 1 + f(y, abs(x - y));
        }
    };
    map<int, int> mp;
    rep(i, n) {
        if (a[i] == 0 && b[i] == 0) continue;
        int v = f(a[i], b[i]);
        c[i] = v;
        mp[v % 3]++;
    }
    // printInline(c)
    int ans = mp.size() <= 1;
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
        solve();
    return 0;
}
