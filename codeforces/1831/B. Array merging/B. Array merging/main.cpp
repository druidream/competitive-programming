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
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vi a(n), b(n);
        int la = 1, lb = 1;
        unordered_map<int, int> ma, mb;
        int ans = 0;
        rep(i, n) {
            cin >> a[i];
            if (i == 0) {
                la = 1;
            } else {
                if (a[i] == a[i - 1]) {
                    la++;
                } else {
                    la = 1;
                }
            }
            ma[a[i]] = max(ma[a[i]], la);
            ans = max(ans, ma[a[i]]);
//            cout << "a: " << a[i] << ' ' << ma[a[i]] << endl;
        }
        rep(i, n) {
            cin >> b[i];
            if (i == 0) {
                lb = 1;
            } else {
                if (b[i] == b[i - 1]) {
                    lb++;
                } else {
                    lb = 1;
                }
            }
            mb[b[i]] = max(mb[b[i]], lb);
//            cout << "b: " << b[i] << ' ' << mb[b[i]] << endl;
            int v = 0;
            if (ma.find(b[i]) != ma.end()) {
                v += ma[b[i]];
            }
            ans = max(ans, v + mb[b[i]]);
        }
        print(ans)
    }
    return 0;
}
