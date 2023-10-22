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
// const int mod = 998244353;
int d4[5] = { 0, 1, 0, -1, 0 };

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;

void solve() {
    int n; cin >> n; 
    ll a, b, c; cin >> a >> b >> c;
    vector<vector<ll>> g(n, vector<ll>(n));
    rep(i, n) {
        rep(j, n) {
            cin >> g[i][j];
        }
    }
    vector<vector<ll>> memo(n, vector<ll>(n, -1));
    function<ll(int, int)> car = [&](int i, int j) -> ll {
        if (i == j) return 0;
        if (memo[i][j] != -1) return memo[i][j];
        ll res = g[i][j] * a;
        for (int k = 0; k < n; k++) {
            res = min(res, car(i, k) + car(k, j));
        }
        memo[i][j] = res;
        return memo[i][j];
    };

    vector<vector<ll>> memo1(n, vector<ll>(n, -1));
    function<ll(int, int)> train = [&](int i, int j) -> ll {
        if (i == j) return 0;
        if (memo1[i][j] != -1) return memo1[i][j];
        ll res = g[i][j] * b + c;
        for (int k = 0; k < n; k++) {
            res = min(res, train(i, k) + train(k, j));
        }
        memo1[i][j] = res;
        return memo1[i][j];
    };
    car(0, n - 1);
    // ll ans = INFF;
    // for (int k = 0; k < n; k++) {
    //     ans = min(ans, car(0, k) + train(k, n - 1));
    // }
    // print(ans)
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
