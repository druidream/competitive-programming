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
    vector<int> ls, rs;
    ll cnt = 0;
    rep(i, n) {
        string op; cin >> op;
        int l, r; cin >> l >> r;
        if (op == "+") {
            cnt += upper_bound(rs.begin(), rs.end(), l) - rs.begin();
            cnt += lower_bound(ls.begin(), ls.end(), r) - ls.begin();
            ls.insert(lower_bound(ls.begin(), ls.end(), l), l);
            rs.insert(lower_bound(rs.begin(), rs.end(), r), r);
        } else {
            cnt -= upper_bound(rs.begin(), rs.end(), l) - rs.begin();
            cnt -= lower_bound(ls.begin(), ls.end(), r) - ls.begin();
            ls.erase(lower_bound(ls.begin(), ls.end(), l));
            rs.erase(lower_bound(rs.begin(), rs.end(), r));
        }
        // printInline(ls)
        bool ans = cnt > 0;
        // print(cnt)
        printBool(ans)
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
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
