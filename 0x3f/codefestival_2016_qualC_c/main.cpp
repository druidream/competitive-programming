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
const int mod = 1e9 + 7;
int d4[5] = { 0, 1, 0, -1, 0 };

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;

void solve() {
    int n; cin >> n;
    vll a(n); rep(i, n) cin >> a[i];
    vll b(n); rep(i, n) cin >> b[i];
    int pos = -1;
    rep(i, n) {
        if (a[i] == b[i]) {
            pos = i;
            break;
        }
    }
    auto checkAsc = [&](vll& arr, int pos) -> bool {
        ll mx = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && arr[i] < arr[i - 1]) return false;
            mx = max(mx, a[i]);
        }
        return a[pos] == mx;
    };
    auto checkDesc = [&](vll& arr, int pos) -> bool {
        ll mx = 0;
        for (int i = 0; i < n; i++) {
            if (i < n - 1 && arr[i] < arr[i + 1]) return false;
            mx = max(mx, a[i]);
        }
        return a[pos] == mx;
    };
    if (pos == -1 || !checkAsc(a, pos) || !checkDesc(b, pos)) {
        print(0)
        return;
    }
    ll ans = 1;
    for (int i = 1; i < n - 1; i++) {
        // if (a[i] == a[pos] && b[i] == b[pos]) continue;
        if (i > 0 && a[i] > a[i - 1]) continue;
        if (i < n - 1 && b[i] > b[i + 1]) continue;
        // cout << a[i] << ' ' << b[i] << endl;
        int mn = min(a[i], b[i]);
        ans = (ans * mn) % mod;
        // if (i > 0 && a[i] < b[i] && a[i] == a[i - 1]) ans = (ans * a[i]) % mod;
        // if (i < n - 1 && b[i] < a[i] && b[i] == b[i + 1]) ans = (ans * b[i]) % mod;
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
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
