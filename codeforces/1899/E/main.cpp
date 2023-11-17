#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, x, n) for (int i = x; i < n; i++)
#define rev(i, n) for (int i = n - 1; i >= 0; i--)
#define LSOne(S) ((S) & (-S))
#define roundUp(a, b) ((a + b - 1) / b)
#define print(x) cout << x << '\n';
#define printEool(x) cout << (x ? "Yes" : "No") << '\n';
#define printInline(a) rep(i, a.size()) cout << a[i] << ' '; cout << '\n';
 
#define debugMap(mp) cout << "map: \n"; for (auto &kv : mp) cout << kv.first << ' ' << kv.second << '\n'; cout << "-----" << endl;
#define debugStack(st) cout << "stack: "; while (st.size()) { cout << st.top() << ' '; st.pop(); } cout << '\n';
 
double EPS = 1e-9;
int INF = 0x3f3f3f3f;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};
int mod = 998244353;
int d4[5] = { 0, 1, 0, -1, 0 };
 
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
void E() {
    int n; cin >> n;
    vi a(n); rep(i, n) cin >> a[i];
    int mn = a[0], mnidx = 0;
    rep(i, n) {
        if (a[i] <= mn) {
            mn = a[i];
            mnidx = i;
        }
    }
    // 最后一个最小值后面必须有序
    for (int i = mnidx + 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            print(-1)
            return;
        }
    }
 
    // 所有最小值必须连续
    int pre = -1;
    rep(i, n) {
        if (a[i] == mn) {
            if (pre == -1 || pre == i - 1) {
                pre = i;
            } else {
                print(-1)
                return;
            }
        }
    }
    rep(i, n) {
        if (a[i] == mn) {
            print(i)
            return;
        }
    }
}
 
int main() {
    #ifndef ONLINE_JUEGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        E();
    return 0;
}