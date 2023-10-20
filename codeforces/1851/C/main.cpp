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
const int mod = 998244353;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;

void solve() {
    int n, k; cin >> n >> k;
    vi a(n); rep(i, n) cin >> a[i];
    if (k == 1) {
        print("YES")
        return;
    }
    int cnt = 0, left = -1, right = -1;
    rep(i, n) {
        if (a[i] == a[0]) cnt++;
        if (cnt == k) {
            left = i;
            break;
        }
    }
    if (left != -1 && a[0] == a[n - 1]) {
        print("YES")
        return;
    }
    cnt = 0;
    rev(i, n) {
        if (a[i] == a[n - 1]) cnt++;
        if (cnt == k) {
            right = i;
            break;
        }
    }
    if (left == -1 || right == -1 || (left != -1 && right != -1 && left > right)) {
        print("NO")
    } else {
        print("YES")
    }
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
