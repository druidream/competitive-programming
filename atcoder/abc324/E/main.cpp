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

void solve() {
    int n; cin >> n;
    string t; cin >> t;
    vector<string> S(n); rep(i, n) cin >> S[i];
    int m = t.size();
    vi pre(n), suf(n);
    auto f = [&](string s) -> int {
        int j = 0, cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == t[j]) {
                cnt++;
                j++;
                if (j == m) break;
            }
        }
        return cnt;
    };
    auto g = [&](string s) -> int {
        int j = m - 1, cnt = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == t[j]) {
                cnt++;
                j--;
                if (j < 0) break;
            }
        }
        return cnt;
    };
    rep(i, n) {
        pre[i] = f(S[i]);
        suf[i] = g(S[i]);
    }
    auto sorted = suf;
    sort(sorted.begin(), sorted.end());
    ll ans = 0;
    rep(i, n) {
        int x = pre[i];
        int y =  m - x;
        int cnt = lower_bound(sorted.begin(), sorted.end(), y) - sorted.begin();
        ans += n - cnt;
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
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
