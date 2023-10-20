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
    ll n, l, r, ql, qr; cin >> n >> l >> r >> ql >> qr;
    vi a(n);
    int pre = 0, suf = 0;
    rep(i, n) {
        cin >> a[i];
        suf += a[i];
    }
    int ans = suf * r + (n - 1) * qr;
    for (int i = 0; i < n; i++) {
        pre += a[i];
        suf -= a[i];
        int curr = pre * l + suf * r;
        int cl = i + 1, cr = n - 1 - i;
        if (cr + 1 < cl) curr += (cl - cr - 1) * ql;
        if (cl + 1 < cr) curr += (cr - cl - 1) * qr;
        // cout << i << ' ' << pre << ' ' << suf << ' ' << curr << endl;
        // if (i + 1 > n - i) curr += (i - (n - i) + 1) * ql; // i - (n - i) - 1
        // if (i + 3 < n - i) curr += ((n - i) - i - 3) * qr;
        ans = min(ans, curr);
    }
    print(ans)
    return 0;
}
