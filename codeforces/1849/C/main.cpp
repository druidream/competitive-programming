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
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vi f(n), g(n);
    int cnt = 0;
    rep(i, n) {
        f[i] = cnt;
        if (s[i] == '0') cnt++;
        else cnt = 0;
    }
    cnt = 0;
    rev(i, n) {
        g[i] = cnt;
        if (s[i] == '1') cnt++;
        else cnt = 0;
    }
    // printInline(f)
    // printInline(g)
    map<int, int> mp; // start, end
    int start = 0;
    rep(i, n) {
        if (s[i] == '0') {
            continue;
        }
        // i == '1';
        if (i == n - 1 || s[i + 1] == '0') {
            mp[start] = i;
            mp[i] = start;
            start = i + 1;
        }
    }
    if (start < n) {
        mp[start] = n - 1;
        mp[n - 1] = start;
    }
    debugMap(mp)


    set<pii> st;
    while (m--) {
        int l, r; cin >> l >> r;
        l--; r--;
        int u = f[l], v = g[r];
        l -= u; r += v;
        // check if (l, r) exist in original string
        // cout << l << ' ' << r << ' ' << u << ' ' << v << endl;
        if ((mp.count(l) && r <= mp[l]) || (mp.count(r) && l >= mp[r])) {
            // cout << 'a' << endl;
            st.insert({ -1, -1 });
        } else {
            // cout << 'b' << endl;
            st.insert({ l, r });
        }
    }
    int ans = st.size();
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
