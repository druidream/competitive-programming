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
    int l, r; cin >> l >> r;
    if (r < 4) {
        print(-1)
        return;
    }
    if (l != r || l % 2 == 0) {
        int a = 2, b = r - 2;
        if (b % 2 == 1) b--;
        cout << a << ' ' << b << "\n";
    } else {
        bool ok = false;
        for (int x = 2; x < r; x++) {
            if (x * x > r) break;
            if (r % x == 0) {
                int a = x, b = r - x;
                cout << a << ' ' << b << "\n"; 
                return;
            }
            // int b = r - a;
            // if (b < a) break;
            // // cout << a << ' ' << b << ' ' << gcd(a, b) << endl;
            // if (gcd(a, b) != 1) {
            //     cout << a << ' ' << b << "\n";
            //     return;
            // }
        }
        print(-1)
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
