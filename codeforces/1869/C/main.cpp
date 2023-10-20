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
    int n, m; cin >> n >> m;
    vector<vector<int>> res(n, vector<int>(m, 0));
    // int pos = 1;
    // for (int v = 0; v < m; v++) {
    //     res[0][pos] = v;
    //     pos = (pos - 1 + m) % m;
    // }
    // for (int i = 1; i < min(m, n); i++) {
    //     for (int j = 0; j < m; j++) {
    //         int pre = -1;
    //         if (j == 0) {
    //             pre = res[i - 1][m - 1];
    //         } else {
    //             pre = res[i - 1][j - 1];
    //         }
    //         res[i][j] = pre;
    //     }
    // }

    // for (int i = ; i < min(m, n); i++) {
    //     vector<int> arr;
    //     for (int j = 0; j < m; j++) {
    //         if (res[i][j] == j) {
    //             res[i][j] = 9;
    //             arr.push_back(j);
    //         }
    //     }
    //     // if (!arr.empty()) {
    //     //     print(arr.size())
    //     //     swap(res[i][arr[0]], res[i][arr[1]]);
    //     // }
    // }
    int pos = 1;
    for (int i = 0; i < min(m - 1, n); i++) {
        for (int j = 0; j < m; j++) {
            res[i][(j + pos) % m] = j;
        }
        pos++;
    }
    if (n > m - 1 && m > 1) {
        for (int i = m - 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[i][j] = res[i - 1][j];
            }
        }
    }
    set<int> rowSet;
    rep(j, m) {
        set<int> colSet;
        rep(i, n) {
            colSet.insert(res[i][j]);
        }
        int colMex = 0;
        while (colSet.count(colMex)) {
            colMex++;
        }
        rowSet.insert(colMex);
    }
    int mex = 0;
    while (rowSet.count(mex)) mex++;
    print(mex)
    rep(i, n) {
        auto line = res[i];
        printInline(line)
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
    cin >> T;
    while (T--)
        solve();
    return 0;
}
