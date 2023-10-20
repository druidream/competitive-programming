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
    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        vector<pair<int, int>> seg;
        rep(i, m) {
            int l, r; cin >> l >> r;
            seg.emplace_back(l, r);
        }
        int q; cin >> q;
        vi qs(q);
        rep(i, q) cin >> qs[i];
        auto check = [&](int x) -> bool {
            vi a(n, 0);
            for (int i = 0; i < x; i++) {
                int u = qs[i];
                u--;
                a[u] = 1;
            }
            vi presum(n + 1, 0);
            rep(i, n) {
                presum[i + 1] = presum[i] + a[i];
            }
            rep(j, m) {
                int l = seg[j].first, r = seg[j].second;
                int len = r - l + 1;
                int cnt = presum[r] - presum[l - 1];
                if (cnt * 2 > len) return true;
            }
            return false;
        };
        int lo = 1, hi = q;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (check(mid)) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        if (lo <= q) {
            print(lo)
        } else {
            print(-1)
        }
    }
    return 0;
}
