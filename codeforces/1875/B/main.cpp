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
    int n, m, k; cin >> n >> m >> k;
    vll a(n); rep(i, n) cin >> a[i];
    vll b(m); rep(i, m) cin >> b[i];
    ll ans = 0;
    int cnt = (k % 2) ? 5 : 4;
    cnt = min(cnt, k);
    int turn = 0;
    while (cnt--) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        ll a0 = a[0], a1 = a[n - 1];
        ll b0 = b[0], b1 = b[m - 1];
        if (turn % 2 == 0) { // Jelly
            if (a[0] < b[m - 1]) {
                a[0] = b1;
                b[m - 1] = a0;
            }
        } else {
            if (b[0] < a[n - 1]) {
                b[0] = a1;
                a[n - 1] = b0;
            }
        }
        // printInline(a)
        // printInline(b)
        turn++;
    }
    rep(i, n) ans += a[i];
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
