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

bool solve() {
    int n; cin >> n;
    vi a(n); rep(i, n) cin >> a[i];
    rep(i, n) {
        while (true) {
            int r = a[i] % 10;
            if (r == 6 || r == 0) break;
            a[i] += a[i] % 10;
        }
        if (i > 0) {
            int r = a[i] % 10;
            if (r != a[0] % 10) return false;
            if (r == 6 && (a[i] / 10) % 2 != (a[0] / 10) % 2) return false;
            if (r == 0 && a[i] != a[0]) return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    while (T--) {
        printBool(solve())
    }
    return 0;
}
