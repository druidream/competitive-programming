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

#define debugMap(mp) cout << "map: \n"; for (auto &kv : mp) cout << kv.first << ' ' << kv.second << '\n'; cout << "-----" << endl;
#define debugStack(st) cout << "stack: "; while (st.size()) { cout << st.top() << ' '; st.pop(); } cout << '\n';

double EPS = 1e-9;
int INF = 0x3f3f3f3f;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};
// const int mod = 998244353;
int d4[5] = { 0, 1, 0, -1, 0 };

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;

bool solve() {
    vector<string> p1(4), p2(4), p3(4);
    rep(i, 4) cin >> p1[i];
    rep(i, 4) cin >> p2[i];
    rep(i, 4) cin >> p3[i];
    int cnt = 0;
    rep(i, 4) {
        rep(j, 4) {
            if (p1[i][j] == '#') cnt++;
            if (p2[i][j] == '#') cnt++;
            if (p3[i][j] == '#') cnt++;
        }
    }
    if (cnt != 16) return false;
    auto rotate = [&](vector<string> &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j ++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    };
    auto bound = [&](vector<string> &p) -> vector<int> { // u, r, d, l
        int u = 3, r = 0, d = 0, l = 3;
        rep(i, 4) {
            rep(j, 4) {
                if (p[i][j] == '.') continue;
                u = min(u, i);
                r = max(r, j);
                d = max(d, i);
                l = min(l, j);
            }
        }
        return { u, r, d, l };
    };
    auto fill = [&](int x, int y, vector<string> &p, vector<string> &g) {
        rep(i, 4) {
            rep(j, 4) {
                if (i + x < 0 || i + x >= 4) continue;
                if (j + y < 0 || j + y >= 4) continue;
                if (p[i][j] == '#') g[i + x][j + y] = '#';
            }
        }
    };
    auto finalCheck = [&](vector<string> &g) -> bool {
        rep(i, 4) {
            rep(j, 4) {
                if (g[i][j] == '.') return false;
            }
        }
        return true;
    };
    auto check = [&](vector<string> &p1, vector<string> &p2, vector<string> &p3) -> bool {
        auto v1 = bound(p1);
        auto v2 = bound(p2);
        auto v3 = bound(p3);
        int u1 = v1[0], r1 = v1[1], d1 = v1[2], l1 = v1[3];
        int u2 = v2[0], r2 = v2[1], d2 = v2[2], l2 = v2[3];
        int u3 = v3[0], r3 = v3[1], d3 = v3[2], l3 = v3[3];
        for (int i1 = -u1; i1 < 4 - d1; i1++) {
            for (int j1 = -l1; j1 < 4 - r1; j1++) {
                for (int i2 = -u2; i2 < 4 - d2; i2++) {
                    for (int j2 = -l2; j2 < 4 - r2; j2++) {
                        for (int i3 = -u3; i3 < 4 - d3; i3++) {
                            for (int j3 = -l3; j3 < 4 - r3; j3++) {
                                vector<string> g(4, "....");
                                fill(i1, j1, p1, g);
                                fill(i2, j2, p2, g);
                                fill(i3, j3, p3, g);
                                if (finalCheck(g)) return true;
                            }
                        }
                    }
                }
                
            }
        }
        return false;
    };
    rep(i, 4) {
        rep(j, 4) {
            rep(k, 4) {
                if (check(p1, p2, p3)) return true;
                rotate(p3);
            }
            rotate(p2);
        }
        rotate(p1);
    }
    return false;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        printBool(solve())
    return 0;
}
