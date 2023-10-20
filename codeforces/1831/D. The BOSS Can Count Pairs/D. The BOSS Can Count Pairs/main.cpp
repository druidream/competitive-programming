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
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vi a(n), b(n);
        rep(i, n) cin >> a[i];
        rep(i, n) cin >> b[i];
        vector<pair<int, int>> arr;
        rep(i, n) {
            arr.push_back({ a[i], b[i] });
        }
        sort(arr.begin(), arr.end());
        ll ans = 0;
        for (int s = 1; s * s <= n * 2; s++) {
            vi cnt(n + 1, 0);
            for (auto [x, y] : arr) {
                int v = s * x - y;
                if (v >= 1 && v <= n) {
                    ans += cnt[v];
                }
                if (x == s) {
                    cnt[y]++;
                }
            }
        }
        print(ans)
    }
    return 0;
}
