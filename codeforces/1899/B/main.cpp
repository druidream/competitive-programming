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
int mod = 998244353;
int d4[5] = { 0, 1, 0, -1, 0 };

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void B() {
    int n; cin >> n;
    vll a(n); 
    ll mx = 0, mn = 1e9;
    rep(i, n) {
        cin >> a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }
    auto calc = [&](ll len) -> ll {
        ll sum = 0, cnt = 0;
        ll mx = 0, mn = INFF;
        rep(i, n) {
            cnt++;
            sum += a[i];
            if (cnt == len) {
                mx = max(mx, sum);
                mn = min(mn, sum);
                cnt = 0;
                sum = 0;
            }
        }
        return mx - mn;
    };
    ll ans = mx - mn;
    for (ll f = 2; f * f <= n; f++) {
        if (n % f == 0) {
            ll x = calc(f);
            ll y = calc(n / f);
            ans = max(ans, x);
            ans = max(ans, y);
        }
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
        B();
    return 0;
}
