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
    string s; cin >> s;
    int n = s.size();
    int len = 0;
    vi f, g;
    rep(i, n) {
        if (s[i] == 'A') {
            len++;
        } else {
            f.push_back(len);
            len = 0;
        }
    }
    len = 0;
    rev(i, n) {
        if (s[i] == 'A') {
            len++;
        } else {
            g.push_back(len);
            len = 0;
        }
    }
    reverse(g.begin(), g.end());
    // printInline(f)
    // printInline(g)
    int m = f.size();
    if (m == 0) {
        print(0)
        return;
    }
    vector<vector<int>> h(m, vector<int>(3, 0));
    h[0][0] = 0; // skip
    h[0][1] = f[0]; // choose left
    h[0][2] = g[0]; // choose right
    for (int i = 1; i < m; i++) {
        h[i][0] = max(h[i - 1][0], max(h[i - 1][1], h[i - 1][2]));
        h[i][1] = max(h[i - 1][0], h[i - 1][1]) + f[i];
        h[i][2] = max(h[i - 1][0], max(h[i - 1][1], h[i - 1][2])) + g[i];
    }
    // rep(i, m) {
    //     auto x = h[i];
    //     printInline(x)
    // }
    int ans = max(h[m - 1][0], max(h[m - 1][1], h[m - 1][2]));
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
