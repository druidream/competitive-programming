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
    ll L; cin >> L;
    int N1, N2; cin >> N1 >> N2;
    vector<pair<ll, ll>> a(N1), b(N2);
    rep(i, N1) {
        ll v, l; cin >> v >> l;
        a[i] = { v, l };
    }
    rep(i, N2) {
        ll v, l; cin >> v >> l;
        b[i] = { v, l };
    }
    ll ans = 0;
    ll i = 0, j = 0, sum1 = 0, sum2 = 0;
    while (i < N1 && j < N2) {
        if (sum1 + a[i].second < sum2 + b[j].second) {
            if (a[i].first == b[j].first) {
                ll right = min(sum1 + a[i].second, sum2 + b[j].second);
                ll left = max(sum1, sum2);
                ans += max(0LL, right - left);
            }
            sum1 += a[i].second;
            i++;
        } else {
            if (a[i].first == b[j].first) {
                ll right = min(sum1 + a[i].second, sum2 + b[j].second);
                ll left = max(sum1, sum2);
                ans += max(0LL, right - left);
            }
            sum2 += b[j].second;
            j++;
        };
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
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
