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
    int n, B; cin >> n >> B;
    vector<pair<int, int>> ps(n);
    rep(i, n) {
        int x, y; cin >> x >> y;
        ps[i] = { x, y };
    }
    auto f = [&](int x, int y) -> int {
        int a = 0, b = 0, c = 0, d = 0;
        rep(i, n) {
            if (ps[i].first < x && ps[i].second < y) a++;
            if (ps[i].first < x && ps[i].second > y) b++;
            if (ps[i].first > x && ps[i].second < y) c++;
            if (ps[i].first > x && ps[i].second > y) d++;
        }
        return max(max(a, b), max(c, d));
    };
    int ans = n;
    vi xs, ys;
    rep(i, n) {
        xs.push_back(ps[i].first - 1);
        xs.push_back(ps[i].first + 1);
        ys.push_back(ps[i].second - 1);
        ys.push_back(ps[i].second + 1);
    }
    for (int i = 0; i < xs.size(); i++) {
        for (int j = 0; j < ys.size(); j++) {
            ans = min(ans, f(xs[i], ys[j]));
        }
    }
    print(ans)
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
