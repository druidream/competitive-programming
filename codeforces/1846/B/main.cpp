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
    vector<string> g(3);
    rep(i, 3) cin >> g[i];
    auto check = [&](char c) -> bool {
        rep(i, 3) {
            if (g[i][0] == c && g[i][1] == c && g[i][2] == c) return true;
            if (g[0][i] == c && g[1][i] == c && g[2][i] == c) return true; 
        }
        if (g[0][0] == c && g[1][1] == c && g[2][2] == c) return true;
        if (g[0][2] == c && g[1][1] == c && g[2][0] == c) return true;
        return false;
    };
    if (check('X')) {
        print("X")
    } else if (check('O')) {
        print("O")
    } else if (check('+')) {
        print("+")
    } else {
        print("DRAW")
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
