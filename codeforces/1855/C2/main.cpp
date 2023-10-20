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
    vi a(n + 1, -20);
    int mx = -20, mn = 20;
    int mxidx = 0, mnidx = 0;
    int pos = 0, neg = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > mx) {
            mx = a[i];
            mxidx = i;
        }
        if (a[i] < mn) {
            mn = a[i];
            mnidx = i;
        }
        if (a[i] > 0) pos++;
        if (a[i] < 0) neg++;
    }
    // printInline(a)
    // cout << "mx: " << mx << ' ' << mn << endl;
    auto makePos = [&](int x) -> vector<pii> {
        vector<pii> res;
        if (x < abs(mn)) {
            while (x < 20) {
                x += x;
                res.push_back({ mxidx, mxidx });
            }
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] < 0) {
                res.push_back({ i, mxidx });
                // a[i] += mx;
            }
        }
        for (int i = 1; i < n; i++) {
            res.push_back({ i + 1, i });
            // a[i + 1] += a[i];
        }
        return res;
    };
    auto makeNeg = [&](int x) -> vector<pii> {
        vector<pii> res;
        if (abs(x) < mx) {
            while (mn > -20) {
                mn += mn;
                res.push_back({ mnidx, mnidx });
                // a[mnidx] += a[mnidx];
            }
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] > 0) {
                res.push_back({ i, mnidx });
                // a[i] += mn;
            }
        }
        for (int i = n - 1; i >= 1; i--) {
            res.push_back({ i, i + 1 });
            // a[i] += a[i + 1];
        }
        return res;
    };

    vector<pii> res;

    if (mx <= 0) {
        for (int i = n - 1; i >= 1; i--) {
            res.push_back({ i, i + 1 });
            // a[i] += a[i + 1];
        }
    } else if (mn >= 0) {
        for (int i = 1; i < n; i++) {
            res.push_back({ i + 1, i });
            // a[i + 1] += a[i];
        }
    } else {
        vector<pii> res1 = makePos(mx);
        vector<pii> res2 = makeNeg(mn);
        if (res1.size() <= 31) res = res1;
        if (res2.size() <= 31) res = res2;
    }
    // printInline(a)
    print(res.size())
    for (auto &[i, j] : res) {
        cout << i << ' ' << j << endl;
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
