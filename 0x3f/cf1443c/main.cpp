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
// const int mod = 998244353;
int d4[5] = { 0, 1, 0, -1, 0 };

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void binarySearch() {
    int n; cin >> n;
    vll a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    auto check = [&](ll k) -> bool {
        ll sum = 0;
        rep(i, n) {
            if (a[i] > k) {
                sum += b[i];
            } 
        }
        return sum <= k;
    };
    ll lo = 1, hi = 1e9;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    print(lo)
}

void sorting() {
    int n; cin >> n;
    vector<pll> a(n);
    ll sum = 0;
    rep(i, n) {
        ll x; cin >> x;
        a[i].first = x;
    }
    rep(i, n) {
        cin >> a[i].second;
        sum += a[i].second;
    }
    sort(a.begin(), a.end());
    ll ans = sum;
    rep(i, n) {
        sum -= a[i].second;
        ll cur = max(a[i].first, sum);
        ans = min(ans, cur);
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
        sorting();
    return 0;
}
