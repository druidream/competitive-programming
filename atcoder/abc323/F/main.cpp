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

void solve() {
    ll xa, ya, xb, yb, xc, yc; cin >> xa >> ya >> xb >> yb >> xc >> yc;
    auto dis = [&](ll x1, ll y1, ll x2, ll y2) -> ll {
        return abs(x1 - x2) + abs(y1 - y2);
    };
    ll ans = 0;//abs(xb - xc) + abs(yb - yc);
    auto yfirst = [&]() -> bool {
        if (ya < yc && yb < yc && abs(ya - yc) > abs(yb - yc)) return true;
        if (ya > yc && yb > yc && abs(ya - yc) > abs(yb - yc)) return true;
        return false;
    };
    if (yfirst()) {
        ll xt = 0, yt = 0;
        if (yb != yc) {
            if (yb < yc) {
                yt = yb - 1;
                xt = xb;
            } else {
                yt = yb + 1;
                xt = xb;
            }
            ans += dis(xa, ya, xt, yt);
            if (xa == xb && xb == xt) ans += 2;
        }
        ans += abs(yb - yc);
        yb = yc;
        xa = xt; ya = (yt > yc) ? yc + 1 : yc - 1;
        if (xb != xc) {
            if (xb < xc) {
                xt = xb - 1;
                yt = yb;
            } else if (xb > xc) {
                xt = xb + 1;
                yt = yb;
            }
            ans += dis(xa, ya, xt, yt);
        }
        ans += abs(xb - xc);
    } else {
        ll xt = 0, yt = 0;
        if (xb != xc) {
            if (xb < xc) {
                xt = xb - 1;
                yt = yb;
            } else if (xb > xc) {
                xt = xb + 1;
                yt = yb;
            }
            ans += dis(xa, ya, xt, yt);
            if (ya == yb && yb == yt) ans += 2;
        }
        ans += abs(xb - xc);
        xb = xc;
        xa = (xt > xc) ? xc + 1 : xc - 1; ya = yt;
        if (yb != yc) {
            if (yb < yc) {
                yt = yb - 1;
                xt = xb;
            } else {
                yt = yb + 1;
                xt = xb;
            }
            ans += dis(xa, ya, xt, yt);
        }
        ans += abs(yb - yc);
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
