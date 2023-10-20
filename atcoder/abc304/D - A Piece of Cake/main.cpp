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
    int w, h; cin >> w >> h;
    int n; cin >> n;
    vector<pair<int, int>> pq(n);
    rep(i, n) {
        int p, q; cin >> p >> q;
        pq[i] = { p, q };
    }
    int A; cin >> A;
    vi a(A); rep(i, A) cin >> a[i];
    int B; cin >> B;
    vi b(B); rep(i, B) cin >> b[i];
    // vector<vector<int>> f(A + 1, vector<int>(B + 1, 0));
    unordered_map<ll, int> mp;
    for (auto &pr : pq) {
        int p = pr.first, q = pr.second;
        int x, y;
        int lo = 0, hi = A - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (a[mid] > p) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        x = lo;

        lo = 0; hi = B - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (b[mid] > q) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        y = lo;
        // cout << x << y << endl;
        // f[x][y] += 1;
        ll key = x * (B + 1) + y;
        mp[key]++;
    }
    int mn = n, mx = 0;
    for (auto &kv : mp) {
        mx = max(mx, kv.second);
        mn = min(mn, kv.second);
    }
    ll tot = (A + 1) * (B + 1);
    if (tot > mp.size()) {
        mn = 0;
    }
    cout << mn << ' ' << mx << '\n';
    return 0;
}
