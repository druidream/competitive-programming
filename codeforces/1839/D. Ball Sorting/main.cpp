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
        vi c(n); rep(i, n) cin >> c[i];
        int l = 0, mx = c[l], r = n - 1, mn = c[r];
        int k = 0, last = 0;
        vi res(n, 0);
        int i = l + 1, j = r - 1;
        while (l < r) {
            while (c[i] >= mx) {
                mx = max(mx, c[i]);
                i++;
            }
            while (c[j] <= mn) {
                mn = min(mn, c[j]);
                j--;
            }
            if (j < l || i - l > r - j) {
                res[k] = r - i;
                l = i;
                i = l + 1;
                cout << "i" << endl;
            } else if (i > r || i - l < r - j) {
                res[k] = j - l;
                r = j;
                j = r - 1;
                cout << "j" << endl;
            }
            cout << l << ' ' << r << ' ' << i << ' ' << j << endl;
            k++;
        }
        // for (int i = 1; i < n; i++) {
        //     if (c[i] < mx) {
        //         res[k] = n - i;
        //         last = n - i;
        //         k++;
        //     }
        //     mx = max(mx, c[i]);
        // }
        // while (k < n) {
        //     res[k] = last;
        //     k--;
        // }
        printInline(res)
    }
    return 0;
}
