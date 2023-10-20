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
    int n; cin >> n;
    vi f(n + 1);
    // f[1] = 1;
    vi res;
    int m = n;
    if (n % 2) m--;
    for (int i = m; i >= 2; i -= 2) {
        // if (f[i]) continue;
        // res.push_back(i);
        // res.push_back(i / 2);
        // f[i] = 1;
        // f[i / 2] = 1;
        if (f[i]) continue;
        int j = i;
        while (j > 1) {
            // print(j)
            if (f[j]) {
                j /= 2;
                continue;
            }
            res.push_back(j);
            f[j] = 1;
            if (j % 2) break;
            j /= 2;
        }
        // print(j)
        // if (j <= n) {
        //     if (i != 2 && !f[2] && i % 2 == 0) {
        //         res.push_back(2);
        //         f[2] = 1;
        //     }
        //     res.push_back(i);
        //     res.push_back(j);
        //     f[i] = 1;
        //     f[j] = 1;
        // }
    }
    for (int i = 1; i <= n; i++) {
        if (!f[i]) res.push_back(i);
    }
    printInline(res)
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
