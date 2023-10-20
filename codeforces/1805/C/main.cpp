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
    vll k(n); rep(i, n) cin >> k[i];
    sort(k.begin(), k.end());
    // (b - k) ^ 2 < 4ac
    // -sqrt(4ac) < b - k < sqrt(4ac)
    // b - sqrt(4ac) < k < b + sqrt(4ac)
    while (m--) {
        ll a, b, c; cin >> a >> b >> c;
        ll u = 4 * a * c;
        if (u < 0) {
            print("NO")
            continue;
        }
        int i = lower_bound(k.begin(), k.end(), b) - k.begin();
        bool ans;
        if (i < n && (k[i] - b) * (k[i] - b) < 4 * a * c) {
            print("YES")
            print(k[i])
            continue;
        }
        if (i > 0 && (k[i - 1] - b) * (k[i - 1] - b) < 4 * a * c) {
            print("YES")
            print(k[i - 1])
            continue;
        }
        print("NO")
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
