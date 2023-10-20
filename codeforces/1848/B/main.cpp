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
    int n, k; cin >> n >> k;
    vi c(n); rep(i, n) cin >> c[i];
    // gaps for each color, break the max into two
    vector<vector<int>> a(k + 1, vector<int>(1, -1)); // pos
    vector<vector<int>> b(k + 1, vector<int>()); // gap
    rep(i, n) {
        int color = c[i];
        b[color].push_back(i - a[color].back() - 1);
        a[color].push_back(i);
    }
    // printInline(a[1])
    // printInline(a[2])

    Rep(i, 1, k + 1) {
        b[i].push_back(n - a[i].back() - 1);
    }
    // printInline(b[1])
    // printInline(b[2])
    int ans = INT_MAX;
    Rep(color, 1, k + 1) {
        sort(b[color].begin(), b[color].end(), greater<int>());
        // printInline(a[color])
        // printInline(b[color])
        if (b[color][0] == 0) {
            ans = 0;
            break;
        }
        if (b[color].size() == 1) {
            ans = min(ans, roundUp(b[color][0] - 1, 2));
            continue;
        }
        int u = roundUp(b[color][0] - 1, 2), v = b[color][1];
        ans = min(ans, max(u, v));
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
    cin >> T;
    while (T--)
        solve();
    return 0;
}
