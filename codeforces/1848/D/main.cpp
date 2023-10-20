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
    // (s + 20x) * (k - 4x)
    // -80x^2 + (20k - 4s)x + ks
    ll s, k; cin >> s >> k;

    function<ll(ll, ll)> f = [&](ll s, ll k) -> int {
        ll ans = k * s;
        if (s % 10 == 0) {
            // do nothing
        } else if (s % 10 != 2) {
            ans = max(ans, f(s + s % 10, k - 1));
        } else {
            
        }
    };



    // if (s == 0) {
    //     print(0)
    //     return;
    // }
    // ll ans = k * s, mx = 0, idx = 0;
    // for (int i = 0; i < k - 1; i++) {
    //     ll ns = s + s % 10;
    //     if (ns == s) break;
    //     ll nv = ns * (k - i - 1);
    //     // if (nv < ans) break;
    //     if (nv > ans) {
    //         mx = ns;
    //         idx = i;
    //         ans = max(ans, nv);
    //     }
    //     s = ns;
    // }
    // cout << mx << ' ' << idx << endl;
    // print(ans)
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
        solve();
    return 0;
}
