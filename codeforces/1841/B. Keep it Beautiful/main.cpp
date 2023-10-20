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
        vi x(n); rep(i, n) cin >> x[i];
        int mn = x[0], pre = x[0];
        bool isFirstPart = true;
        string s = "1";
        for (int i = 1; i < n; i++) {
            if (isFirstPart) {
                if (x[i] >= pre) {
                    pre = x[i];
                    s += "1";
                } else if (x[i] > mn) {
                    s += "0";
                } else { // <= mn
                    isFirstPart = false;
                    pre = x[i];
                    s += "1";
                }
            } else {
                if (x[i] >= pre && x[i] <= mn) {
                    s += "1";
                    pre = x[i];
                } else {
                    s += "0";
                }
            }
        }
        print(s)
    }
    return 0;
}
