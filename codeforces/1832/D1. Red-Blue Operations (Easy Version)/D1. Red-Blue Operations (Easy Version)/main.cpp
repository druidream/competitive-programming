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
    int n, q; cin >> n >> q;
    vll a(n); rep(i, n) cin >> a[i];
    vll k(q); rep(j, q) cin >> k[j];
    sort(a.begin(), a.end());
    vll res(q);
    rep(j, q) {
        if (k[j] <= n) {
            ll ans = INFF;
            for (int i = 0; i < n; i++) {
                if (i < k[j]) {
                    ans = min(ans, a[i] + k[j] - i);
                } else {
                    ans = min(ans, a[i]);
                }
            }
            res[j] = ans;
        } else {
            vll b = a;
            ll posCnt = n;
            ll extra = k[j] - n;
            if (extra % 2 == 1) {
                extra++;
                posCnt--;
            }
            for (ll i = 0; i < posCnt; i++) {
                b[i] += k[j] - i;
            }
            extra /= 2;
            sort(b.begin(), b.end(), greater<int>());
            ll ans = b[n - 1];
            for (int i = 0; i < n; i++) {
                if (i != n - 1) {
                    ll diff = b[i] - b[i + 1];
                    extra -= diff * (i + 1);
                    if (extra <= 0) break;
                } else {
                    ans -= roundUp(extra, n);
                }
            }
            res[j] = ans;
        }
    }
    printInline(res)
    return 0;
}
