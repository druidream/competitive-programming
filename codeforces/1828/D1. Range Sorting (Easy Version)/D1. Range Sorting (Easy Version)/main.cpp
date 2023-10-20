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
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vi a(n); rep(i, n) cin >> a[i];
        ll ans = 0;
        for (int i = n - 1; i >= 0; i--) {
//            cout << ans << endl;
            int r = i, fl = true, orderlen = 1, mnlen = 0, mn = a[i], mx = a[i];
            for (int j = i - 1; j >= 0; j--) {
                mx = max(mx, a[j]);
                mn = min(mn, a[j]);
                if (mx == a[i] && mn == a[j]) {
                    if (fl) {
                        orderlen++;
                        r--;
                    }
                } else {
                    fl = false;
                }
                if (mn == a[j]) {
                    mnlen++;
                } else {
                    mnlen = 0;
                }
                int lo = i - orderlen + 1, hi = i;
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;
                    if (a[mid] > a[j]) {
                        hi = mid - 1;
                    } else {
                        lo = mid + 1;
                    }
                }
                r = max(hi, r);
                if (r == i - orderlen) {
                    int d = i - j - mnlen - orderlen;
                    ans += d;
//                    cout << a[j] << ' ' << a[i] << " d: " << d << " hi: " << hi << ' ' << orderlen << endl;
                } else {
                    int d = max(0, r - j - mnlen);
//                    cout << a[j] << ' ' << a[i] << " d: " << d << " hi: " << hi << ' ' << orderlen << endl;
//                    cout << "ans2: " << ans << endl;
                    ans += d;
                    
                }
            }
        }
        print(ans)
    }
    return 0;
}
