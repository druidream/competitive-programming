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
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<int> time(m);
    vector<int> good(m), bad(m);

    rep(i, m) {
        string a, b; 
        cin >> time[i] >> a >> b;
        int u = 0, v = 0;
        rep(j, n) {
            if (a[j] == '1') u |= (1 << j);
            if (b[j] == '1') v |= (1 << j);
        }
        good[i] = u;
        bad[i] = v;
    }

    // vector<int> memo(1 << n, INT_MAX);
    // function<int(int)> dfs = [&](int x) -> int {
        
    //     if (x == 0) return 0;
    //     if (memo[x] != INT_MAX) return memo[x];
    //     int res = INT_MAX;
    //     rep(i, m) {
    //         if ((x & good[i]) == 0) continue;
    //         int y = x ^ (x & good[i]);
    //         y |= bad[i];
    //         res = min(res, dfs(y));
    //     }
    //     memo[x] = res;
    //     return res;
    // };
    // int mask = 0;
    // rep(i, n) {
    //     if (s[i] == '1') mask |= (1 << i);
    // }
    // int ans = dfs(mask);
    // print(ans)
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
