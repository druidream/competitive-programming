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
    int a, b, k; cin >> a >> b >> k;
    auto isPrime = [&](int x) -> bool {
        if (x == 1) return false;
        for (int f = 2; f * f <= x; f++) {
            if (x % f == 0) return false;
        }
        return true;
    };
    vi f(b - a + 1);
    for (int i = a; i <= b; i++) {
        f[i - a] = isPrime(i);
    }
    // cout << f[0] << f[1] << f[2] << f[3] << f.size() << endl;
    auto check = [&](int l) -> bool {
        int cnt = 0;
        for (int i = a; i <= b; i++) {
            if (f[i - a]) cnt++;
            if (i >= a + l) {
                if (f[i - l - a]) cnt--;
            }
            if (i >= a + l - 1) {
                if (cnt < k) return false;
            }
        }
        return true;
    };
    int lo = 1, hi = b - a + 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    int ans = lo > b - a + 1 ? -1 : lo;
    print(ans)
    return 0;
}
