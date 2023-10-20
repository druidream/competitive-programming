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
    vi a(n); rep(i, n) cin >> a[i];
    int ans = INT_MAX, dec = 0, inc = 0;

    for (int i = 1; i < n; i++) {
        if (a[i - 1] >= a[i]) dec++;
    }
    ans = dec;

    // length of neg prefix
    for (int len = 0; len <= n; len++) {
        // additional op to flip the prefix, only needed when len > 0
        int negOp = len > 0; 
        if (len > 0) {
            // a[i] will become neg
            int i = len - 1;
            // pair a[i], a[i + 1] become sorted automatically
            if (i + 1 < n && a[i] >= a[i + 1]) dec--;
            // a[i - 1], a[i] are neg, if a[i - 1] <= a[i], then -a[i - 1] >= -a[i]
            // one op is needed to make them sorted
            if (i > 0 && i < n && a[i - 1] <= a[i]) inc++;
        }
        // cout << inc << ' ' << dec << ' ' << ans << ' ' << negOp << endl;
        ans = min(ans, inc + dec + negOp);
    }
    // for (int i = 1; i < n; i++) {
    //     if (a[i - 1] <= a[i]) inc++;
    //     if (a[i - 1] >= a[i]) dec--;
    //     cout << inc << ' ' << dec << ' ' << ans << endl;
    //     ans = min(ans, inc + dec + 1);
    // }


    // for (int i = 1; i < n; i++) {
    //     if (a[i] == a[i - 1]) ans++;
    //     if (a[i - 1] > a[i]) dec++;
    // }
    // ans += dec;
    // int tot = dec;
    // int inc = 0;
    // for (int i = 1; i < n; i++) {
    //     if (a[i - 1] > a[i]) {
    //         dec--;
    //     } else {
    //         inc++;
    //     }
    //     if (dec < tot) {
    //         ans = min(ans, inc + 1 + dec);    
    //     }
    //     // cout << inc << ' ' << dec << ' ' << ans << endl;
    // }
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
