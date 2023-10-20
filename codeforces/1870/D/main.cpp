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

// WA
void solve1() {
    int n; cin >> n;
    priority_queue<pair<int, int>> pq;
    vi c(n); 
    rep(i, n) {
        cin >> c[i];
        pq.push({ -c[i], -i });
    }
    int k; cin >> k;
    int pos = 0;
    vi a(n, 0);
    int pre = 0, pre_i = -1;
    while (!pq.empty() && k) {
        auto [v, i] = pq.top(); pq.pop();
        v = -v; i = -i;
        if (i < pos) continue;
        if (a[i] > 0) continue;
        pos = max(pos, i);
        int diff = (v - pre);
        if (diff == 0) continue;
        int cnt = 0;
        if (pre_i == -1) {
            cnt = k / diff;
        } else {
            cnt = min(a[pre_i], k / diff);
        }
        if (pre_i != -1) a[pre_i] -= cnt;
        a[i] += cnt;
        k %= (v - pre);
        pre = v;
        pre_i = i;
    }
    int sum = 0;
    rev(i, n) {
        sum += a[i];
        a[i] = sum;
    }
    printInline(a)
}

void solve2() {
    int n; cin >> n;
    vi c(n); 
    rep(i, n) {
        cin >> c[i];
    }
    for (int i = n - 1; i > 0; i--) {
        c[i - 1] = min(c[i - 1], c[i]);
    }
    // printInline(c)
    int k; cin >> k;
    int pos = 0;
    vi a(n, 0);
    a[0] = k / c[0];
    k -= c[0] * a[0];
    for (int i = 1; i < n; i++) {
        int diff = c[i] - c[i - 1];
        if (diff == 0) {
            a[i] = a[i - 1];
            continue;
        }
        a[i] = min(a[i - 1], k / diff);
        k -= a[i] * diff;
    }
    printInline(a)
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
        solve2();
    return 0;
}
