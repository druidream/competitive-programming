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
    vi a(n); rep(i, n) cin >> a[i];
    vector<vector<int>> f(n + 1, vector<int>(3));
    for (int i = 0; i < n; i++) {
        f[i + 1][0] = max(f[i][0], max(f[i][1], f[i][2]));
        if (a[i] == 1 || a[i] == 3) {
            f[i + 1][2] = max(f[i][0], f[i][1]) + 1;
        }
        if (a[i] == 2 || a[i] == 3) {
            f[i + 1][1] = max(f[i][0], f[i][2]) + 1;
        }
    }
    int ans = n - max(f[n][0], max(f[n][1], f[n][2]));
    print(ans)
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int T; cin >> T;
    // while (T--)
        solve();
    return 0;
}
