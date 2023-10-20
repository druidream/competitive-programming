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

void solve() {
    int a, b, c; cin >> a >> b >> c;
    ll k; cin >> k;
    int mx = max(a, b), mn = min(a, b);
    if (c < mx || c > mx + 1) {
        print(-1)
        return;
    }
    ll u = 1, v = 1, w = 1;
    rep(i, a - 1) u *= 10;
    rep(i, b - 1) v *= 10;
    rep(i, c) w *= 10;
    // cout << u << ' ' << v << endl;
    if (c == mx) {
        if (a == b) {
            ll x = u * 9;
            ll cnt = (x + 1) * x / 2;
            if (k > cnt) {
                print(-1)
                return;
            }
            ll sum = u * 10 - 1;
            ll cur = sum - 1;
            // cout << sum << endl;
            int p = 1, q = 0;
            while (k) {
                if (k > cur) {
                    k -= cur;
                    cur--;
                    p++;
                } else {
                    q = k;
                    k = 0;
                }
            }
            cout << p << " + " << q << " = " << p + q << endl;
        } else {
            ll x = min(u, v), y = max(u, v);
            ll cnt1 = x * 9 * y * 8;
            ll cnt2 = (1 + x * 9) * x * 9 / 2;
            if (k > cnt1 + cnt2) {
                print(-1)
                return;
            }
            ll cur = x;
            ll sum = w - u - 1;
            // cout << cur << ' ' << sum  << ' ' << u << endl;
            int p = u, q = 0;
            while (k) {
                if (k > cur) {
                    k -= cur;
                    cur++;
                    p++;
                } else {
                    q = sum - cur + k - 1;
                    k = 0;
                }
            }
            cout << p << " + " << q << " = " << p + q << endl;
        }
    } else { // c == mx + 1
        if (a == b) {
            ll cnt1 = (u + u * 9 - 1) * u * 8 / 2;
            ll cnt2 = u * 9 * u;
            if (k > cnt1 + cnt2) {
                print(-1)
                return;
            }
            ll sum = u * 10;
            ll cur = u;
            // cout << cur << ' ' << sum << endl;
            int p = u, q = 0;
            while (k) {
                if (k > cur) {
                    k -= cur;
                    cur = min(u * 9, cur + 1);
                    p++;
                } else {
                    q = sum - p + k - 1;
                    k = 0;
                }
            }
            cout << p << " + " << q << " = " << p + q << endl;
        } else {
            ll x = min(u, v), y = max(u, v);
            ll cnt = (1 + x * 9) * x * 9 / 2;
            if (k > cnt) {
                print(-1)
                return;
            }
            ll cur = x;
            ll sum = w;
            int p = u, q = 0;
            
            while (k) {
                // cout << cur << ' ' << sum << endl;
                if (k > cur) {
                    k -= cur;
                    cur++;
                    p++;
                } else {
                    q = sum - cur + k - 1;
                    k = 0;
                }
            }
            cout << p << " + " << q << " = " << p + q << endl;
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int ab = 0 ^ 1;
    int bc = 1 ^ 2;
    int cd = 2 ^ 3;
    int x = 4 ^ 5;
    print(ab)
    print(bc)
    print(cd)
    print(x)
    int T; cin >> T;
    while (T--) {
        // solve();
    }
    return 0;
}
