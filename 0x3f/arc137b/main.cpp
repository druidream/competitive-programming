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

int maxSubarray(vector<int>& a) {
    int sum = 0;
    int mx = -1e9;
    for (auto &x : a) {
        sum = max(x, sum + x);
        mx = max(mx, sum);
    }
    return mx;
}

int minSubarray(vector<int>& a) {
    int sum = 0;
    int mn = 1e9;
    for (auto &x : a) {
        sum = min(x, sum + x);
        mn = min(mn, sum);
    }
    return mn;
}

void solve() {
    int n; cin >> n;
    vi a(n); 
    rep(i, n) {
        int x; cin >> x;
        a[i] = (x == 1) ? -1 : 1;
    }
    int mx = maxSubarray(a);
    int mn = minSubarray(a);
    mx = max(mx, 0);
    mn = min(mn, 0);
    // printInline(a)
    // cout << mx << ' ' << mn << endl;
    int ans = mx - mn + 1;
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
