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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k; cin >> n >> k;
    vi v(n); rep(i, n) cin >> v[i];
    sort(v.begin(), v.end());
    auto check = [&](int mx) -> bool {
        int j0 = 0;
        vi f(n + 1, false);
        f[0] = true;
        for (int i = k - 1; i < n; i++) {
            while (v[i] - v[j0] > mx) {
                j0++;
            }
            for (; j0 <= i - k + 1; j0++) {
                if (f[j0]) {
                    f[i + 1] = true;
                    break;
                }
            }
        }
        return f[n];
    };
    int lo = 0, hi = 1e9;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    print(lo)
    return 0;
}
