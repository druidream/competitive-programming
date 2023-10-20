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
    int n, m, h; cin >> n >> m >> h;
    vector<vector<int>> g(n, vector<int>(m, 0));
    rep(i, n) {
        rep(j, m) {
            cin >> g[i][j];
        }
    }
    vector<tuple<ll, ll, int>> arr;
    rep(i, n) {
        sort(g[i].begin(), g[i].end());
        ll cur = 0, cnt = 0, tot = 0;
        rep(j, m) {
            cur += g[i][j];
            if (cur <= h) {
                cnt++;
                tot += cur;
            }
        }
        arr.push_back({ -cnt, tot, i });
    }
    sort(arr.begin(), arr.end());
    rep(i, n) {
        auto item = arr[i];
        if (get<2>(item) == 0) {
            print(i + 1)
            break;
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
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
