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

#define debugStack(st) cout << "stack: "; auto st_ = st; while (st_.size()) { cout << st_.top() << ' '; st_.pop(); } cout << '\n';

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
    vi lmn(n, -1), rmn(n, n), lmx(n, -1), rmx(n, n);
    stack<int> st;
    rep(i, n) {
        while (!st.empty() && p[st.top()] > p[i]) {
            st.pop();
        }
        if (!st.empty()) {
            lmn[i] = st.top();
        }
        st.push(i);
    }
    // debugStack(st)

    st = stack<int>();
    rev(i, n) {
        while (!st.empty() && p[st.top()] > p[i]) {
            st.pop();
        }
        if (!st.empty()) {
            rmn[i] = st.top();
        }
        st.push(i);
    }
    st = stack<int>();
    rep(i, n) {
        while (!st.empty() && p[st.top()] < p[i]) {
            st.pop();
        }
        if (!st.empty()) {
            lmx[i] = st.top();
        }
        st.push(i);
    }
    st = stack<int>();
    rev(i, n) {
        while (!st.empty() && p[st.top()] < p[i]) {
            st.pop();
        }
        if (!st.empty()) {
            rmx[i] = st.top();
        }
        st.push(i);
    }
    printInline(lmn)
    printInline(rmn)
    printInline(lmx)
    printInline(rmx)
    st = stack<int>();
    int ans = 0;
    auto count = [&](int i, int j) -> int {
        int v = 0;
        int l1 = lmn[i], r1 = rmn[i];
        int l2 = lmx[j], r2 = rmx[j];
        v += max(0, min(r1, r2) - max(l1, l2) - 1 - (j - i));
        cout << i << ' ' << j << ' ' << v << endl;
        return v;
    };
    int mn = p[0];
    st.push(0);
    Rep(i, 0, n) {
        cout << i << ' ' << p[i] << endl;
        if (p[i] < mn) {
            mn = p[i];
            st = stack<int>();
            st.push(i);
            continue;
        }
        while (st.size() > 1 && p[st.top()] < p[i]) {
            ans += count(st.top(), i);
            st.pop();
        }
        if (!st.empty() && p[st.top()] < p[i]) {
            ans += count(st.top(), i);
        }
        st.push(i);
        debugStack(st)
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
