#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, x, n) for (int i = x; i < n; i++)
#define rev(i, n) for (int i = n - 1; i >= 0; i--)
#define LSOne(S) ((S) & (-S))
#define roundUp(a, b) ((a + b - 1) / b)
#define print(x) cout << x << '\n';
#define printBool(x) cout << (x ? "YES" : "NO") << '\n';
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
    ll a, b, c; cin >> a >> b >> c;
    ll sum = a + b + c;
    vll f = { a, b, c };
    sort(f.begin(), f.end());
    bool ans = false;
    for (int seg = 3; seg <= 6; seg++) {
        if (sum % seg) continue;
        if (seg == 3) {
            if (f[0] == f[1] && f[1] == f[2]) ans = true;
        } else if (seg == 4) {
            if (f[0] == f[1] && f[2] == f[1] * 2) ans = true;
        } else if (seg == 5) {
            if (f[0] == f[1] && f[2] == f[1] * 3) ans = true;
            if (f[1] == f[2] && f[1] == f[0] * 2) ans = true;
        } else {
            if (f[0] == f[1] && f[2] == f[1] * 4) ans = true;
            if ((f[1] == f[0] * 2) && (f[2] == f[0] * 3)) ans = true;
        }
    }
    printBool(ans)
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
