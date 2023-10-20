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

double EPS = 1e-9;
int INF = 0x3f3f3f3f;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};
const int mod = 998244353;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;

void solve() {
    int n; cin >> n;
    vi a(n); rep(i, n) cin >> a[i];
    vi even, odd;
    rep(i, n) {
        if (a[i] % 2 == 0) {
            even.push_back(i);
        } else {
            odd.push_back(i);
        }
    }
    // printInline(even)
    // printInline(odd)
    sort(a.begin(), a.end());
    int p = 0, q = 0;
    bool ans = true;
    rep(i, n) {
        if (a[i] % 2 == 0) {
            if (even[p] != i) {
                ans = false;
                break;
            } else {
                p++;
            }
        } else {
            if (odd[q] != i) {
                ans = false;
                break;
            } else {
                q++;
            }
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
