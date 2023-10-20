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
    int n, k; cin >> n >> k;
    vll a(n); rep(i, n) cin >> a[i];
    vll h(n); rep(i, n) cin >> h[i];
    auto check = [&](int x) -> bool {
        int left = 0;
        ll sum = 0;
        rep(i, n) {
            if (i == 0 || (i > 0 && h[i - 1] % h[i] == 0)) {
                sum += a[i];
                if (i - left + 1 > x) {
                    sum -= a[left];
                    left++;
                }
                if (i - left + 1 == x && sum <= k) {
                    return true;
                }
            } else {
                left = i;
                sum = 0;
            }
        }
        return false;
    };
    int lo = 0, hi = n;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    print(hi)
}

void solve1() {
    int n, k; cin >> n >> k;
    vll a(n); rep(i, n) cin >> a[i];
    vll h(n); rep(i, n) cin >> h[i];
    int ans = 0, left = 0;
    rep(i, n) {
        if (a[i] <= k) {
            ans = 1;
            break;
        }
    }
    ll sum = a[0];
    for (int i = 1; i < n; i++) {
        if (h[i - 1] % h[i] == 0) {
            sum += a[i];
            while (sum > k) {
                sum -= a[left];
                left++;
            }
            ans = max(ans, i - left + 1);
        } else {
            sum = a[i];
            left = i;
        }
        // cout << i << ' ' << h[i] << ' ' << sum << ' ' << left << endl;
    }
    print(ans)
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
        solve1();
    return 0;
}
