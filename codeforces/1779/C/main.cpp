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

// https://codeforces.com/contest/1779/submission/187800994
void solve() {
    int n, m; cin >> n >> m;
    vll a(n); rep(i, n) cin >> a[i];
    // if (n == 1) {
    //     print(0)
    //     return;
    // }
    m--;
    int ans = 0;
    priority_queue<int> pq;
    // ll sum = 0;
    // for (int i = 0; i < m; i++) {
    //     sum += a[i];
    // }
    ll cur = 0;
    // turn max positive in [x + 1, m] into negative
    for (int i = m; i >= 0; i--) {
        while (cur > 0) {
            auto v = pq.top(); pq.pop();
            cur = cur - v - v;
            ans++;
        }
        cur += a[i];
        pq.push(a[i]);
    }
    // turn min negative in [m + 1, x] into positive
    pq = priority_queue<int>();
    cur = 0;
    for (int i = m + 1; i < n; i++) {
        cur += a[i];
        pq.push(-a[i]);
        while (cur < 0) {
            auto v = -pq.top(); pq.pop();
            cur = cur - v - v;
            ans++;
        }
    }
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
