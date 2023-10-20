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

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi a(n); rep(i, n) {
        cin >> a[i];
    }
    int sum = accumulate(a.begin(), a.end(), 0);
    if (sum % 2 == 1) {
        print(0)
        return;
    }
    vi f(sum + 1);
    f[a[0]] = 1;
    for (int i = 1; i < n; i++) {
        for (int v = sum; v >= 0; v--) {
            if (v - a[i] < 0) break;
            if (f[v - a[i]] == 1) {
                f[v] = 1;
            }
        }
    }
    if (f[sum / 2] == 1) {
        int idx = -1, mn = INT_MAX;
        rep(i, n) {
            int v = LSOne(a[i]);
            if (v < mn) {
                mn = v;
                idx = i;
            }
        }
        print(1)
        print(idx + 1)
    } else {
        print(0)
    }
    return;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; 
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
