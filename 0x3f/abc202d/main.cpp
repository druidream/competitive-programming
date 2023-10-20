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
    ll a, b, k; cin >> a >> b >> k;
    ll len = a + b;
    vector<vector<ll>> f(a + b + 1, vector<ll>(a + b + 1, 0));
    for (int i = 0; i <= a + b; i++) {
        f[i][0] = 1;
    }
    for (int i = 1; i <= a + b; i++) {
        for (int j = 1; j <= i; j++) {
            f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
        }
    }
    // rep(i, a + b + 1) {
    //     auto arr = f[i];
    //     printInline(arr)
    // }
    string s = "";

    for (int i = 0; i < len; i++) {
        if (a == 0) {
            s += string(b, 'b');
            break;
        } else {
            ll m = a + b - 1, n = b;
            ll cnt = f[m][n];
            // cout << i << ' ' << a << ' ' << b << ' ' << m << ' ' << n << ' ' << cnt << endl;
            if (cnt >= k) {
                s += 'a';
                a--;
            } else {
                s += 'b';
                b--;
                k -= cnt;
            }
        }
    }
    print(s)
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
