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
    int n, m; cin >> n >> m;
    vector<pair<int, int>> edges(m);
    rep(i, m) {
        int x, y; cin >> x >> y;
        edges.emplace_back(x, y);
    }
    vector<UnionFind *> pre(n + 1), suf(n + 1);
    UnionFind *uf = UnionFind(n + 1);
    for (int i = 0; i < m; i++) {
        UnionFind *ufi = uf;
        int x = edges[i][0], y = edges[i][1];
        ufi.union(x, y);
        pre[i + 1] = ufi;
        uf = ufi;
    }
    uf = UnionFind(n + 1);
    for (int i = m - 1; i >= 0; i--) {
        UnionFind *ufi = uf;
        int x = edges[i][0], y = edges[i][1];
        ufi.union(x, y);
        suf[i] = ufi;
        uf = ufi;
    }
    int k; cin >> k;
    for (int j = 0; j < k; j++) {
        int l, r; cin >> l >> r;
        UnionFind *a = pre[l], b = suf[r];
        for (int i = 0; i < n; i++) {
            
        }
    }

    return 0;
}
