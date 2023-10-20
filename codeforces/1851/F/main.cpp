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
    int n, k; cin >> n >> k;
    vi a(n); rep(i, n) cin >> a[i];
    int mask = 0;
    int mx = 0;
    vi f(3);
    f[0] = 1; f[1] = 2;
    for (int i = k - 1; i >= 0; i--) {
        mask |= 1 << i;
        map<int, int> mp;
        bool ok = false;
        for (int j = 0; j < n; j++) {
            int x = a[j];
            int left = x & mask;
            if (mp.count(left)) {
                mx |= 1 << i;
                f[0] = mp[left] + 1;
                f[1] = j + 1;
                ok = true;
                break;
            }
            mp[left] = j;
        }
        if (!ok) {
            mask ^= 1 << i;
        }
    }
    // print(mask)
    // print(mx)
    // f[2] = mask;
    int x = 0;
    int u = a[f[0] - 1], v = a[f[1] - 1];
    for (int i = 0; i < k; i++) {
        if ((u >> i & 1) == 0 && (v >> i & 1) == 0) {
            x |= 1 << i;
        }
    }
    f[2] = x;
    printInline(f)
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
