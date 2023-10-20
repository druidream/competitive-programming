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

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vi a(n); rep(i, n) cin >> a[i];
    vector<vi> f(n, vi(2));
    f[0][0] = a[0] < 0;
    f[0][1] = a[0] > 0;
    Rep(i, 1, n) {
        if (a[i] > 0) {
            f[i][0] = f[i - 1][0];
            f[i][1] = f[i - 1][1] + 1;
        } else {
            f[i][0] = f[i - 1][1] + 1;
            f[i][1] = f[i - 1][0];
        }
    }
    ll u = 0, v = 0;
    rep(i, n) {
        u += f[i][0];
        v += f[i][1];
    }
    cout << u << ' ' << v << '\n';
    return 0;
}
