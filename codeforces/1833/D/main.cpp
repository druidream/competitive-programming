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
    vi p(n); rep(i, n) cin >> p[i];
    int r = 0;
    for (int i = 0; i < n; ++i) {
        if (p[min(n-1, r+1)] <= p[min(n-1, i+1)]) {
            r = i;
        }
    }
    print(r)
    print(p[r])
    // int k = n;
    // if (p[0] == n) k--;
    // print(k)
    // int l, r;
    // rep(i, n) {
    //     if (p[i] == k) { // find r
    //         r = i - 1;
    //         l = i - 2;
    //         break;
    //     }
    // }
    // print(r)
    // for (int i = l; i >= 0; i--) {
    //     if (a[i] > a[0]) {
    //         l = i;
    //     } else {
    //         break;
    //     }
    // }
    // // print(l)
    // // print(r)
    // vi res;
    // for (int i = r; i < n; i++) {
    //     res.push_back(a[i]);
    // }
    // for (int i = r - 1; i >= l; i--) {
    //     res.push_back(a[i]);
    // }
    // for (int i = 0; i < l; i++) {
    //     res.push_back(a[i]);
    // }
    // printInline(res)
    // reverse(a.begin(), a.end());
    // int k = n;
    // int suf = false;
    // if (a[n - 1] == n) {
    //     k--;
    //     suf = true;
    // }
    // // print(k)
    // auto f = [&](int i, int j) {
    //     while (i < j) {
    //         swap(a[i], a[j]);
    //         i++;
    //         j--;
    //     }
    // };
    // for (int i = 0; i < n; i++) {
    //     // print(i)
    //     // printInline(a)
    //     if (a[i] == k) {
    //         // reverse(a.begin(), a.begin() + i + 1);
    //         f(0, i);
    //         i++;
    //         suf = true;
    //         continue;
    //     }
    //     if (suf && a[i] < a[n - 1]) {
    //         // reverse(a.begin() + i + 1, a.end());
    //         f(i, n - 1);
    //         break;
    //     }
    // }
    // printInline(a)
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
