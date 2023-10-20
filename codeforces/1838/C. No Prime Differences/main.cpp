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
        int n, m; cin >> n >> m;
        vector<vector<int>> a;
        for (int i = 0; i < n; i += 2) {
            vector<int> row(m, 0);
            for (int j = 0; j < m; j++) {
                row[j] = i * m + j + 1;
            }
            a.push_back(row);
        }
        reverse(a.begin(), a.end());
        int mx = (n % 2 == 0) ? n : n - 1;
        for (int i = mx - 1; i > 0; i -= 2) {
            vector<int> row(m, 0);
            for (int j = 0; j < m; j++) {
                row[j] = i * m + j + 1;
            }
            a.push_back(row);
        }
        rep(i, n) {
            rep(j, m) {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
