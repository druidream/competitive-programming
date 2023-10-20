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
    int n, m, d; cin >> n >> m >> d;
    vi a(m); rep(i, m) cin >> a[i];
    int cnt = 1;
    rep(i, m) {
        int start = i > 0 ? a[i - 1] : 1;
        cnt += roundUp(a[i] - start, d);
    }
    map<int, int> mp;
    cnt += (n - a[m - 1]) / d;
    // print(cnt)
    // remove a[i]
    rep(i, m) {
        int v = cnt;
        int start = i > 0 ? a[i - 1] : 1;
        int end = i + 1 < m ? a[i + 1] : n + 1;
        // cout << "start: " << start << ", end: " << end << endl;
        v -= roundUp(a[i] - start, d);
        // print(v)
        v -= roundUp(end - a[i], d);
        // print(v)
        v += roundUp(end - start, d);
                // print(v)
        mp[v]++;
        // cout << "i: " << i << ", a[i]: " << a[i] << ", v: " << v << endl;
    }
    int mn = INF;
    for (auto &kv: mp) {
        mn = min(mn, kv.first);
    }
    cout << mn << ' ' << mp[mn] << '\n';
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
