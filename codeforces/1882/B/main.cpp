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
const int mod = 998244353;
int d4[5] = { 0, 1, 0, -1, 0 };

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;

void solve() {
    int n; cin >> n;
    vi f(51, 0);
    map<int, vector<int>> mp; // num: set idx
    vector<vector<int>> sets(n);
    rep(i, n) {
        int k; cin >> k;
        rep(j, k) {
            int x; cin >> x;
            sets[i].push_back(x);
            mp[x].push_back(i);
            f[x]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= 50; i++) {
        if (f[i] == 0) continue;
        // remove num i
        auto g = f;
        for (int j = 0; j < mp[i].size(); j++) {
            int idx = mp[i][j];
            for (auto &x : sets[idx]) {
                g[x]--;
            }
        }
        int cnt = 0;
        for (int j = 1; j <= 50; j++) {
            if (g[j] > 0) cnt++;
        }
        ans = max(ans, cnt);
    }
    print(ans)
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
