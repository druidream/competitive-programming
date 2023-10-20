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
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        ll ans = 0, sum = 0;
        vi a(n);
        rep(i, n) {
            cin >> a[i];
            sum += abs(a[i]);
        }
        int i = 0;
        while (i < n) {
            if (a[i] >= 0) {
                i++;
            } else {
                ans++;
                while (i < n && a[i] <= 0) {
                    i++;
                }
            }
        }
        // int pre = 1;
        // rep(i, n) {
        //     if (a[i] < 0) {
        //         if (i == 0 || pre > 0) {
        //             ans++;
        //         }
        //     }
        //     if (a[i] != 0) pre = a[i];
        //     sum += abs(a[i]);
        // }
        cout << sum << ' ' << ans << endl;
    }
    return 0;
}
