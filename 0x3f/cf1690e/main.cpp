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
    int n, k; cin >> n >> k;
    vector<vector<ll>> a(k);
    rep(i, n) {
        ll x; cin >> x;
        a[x % k].push_back(x);
    }
    int left = 0;
    ll ans = 0;
    for (ll right = k - 1; right >= k / 2; right--) {
        while (!a[right].empty()) {
            while ((left + right < k) || a[left].empty()) {
                left++;
            }
            if (left > right || (left == right && a[right].size() == 1)) break;
            ll x = a[right].back();
            a[right].pop_back();
            ll y = a[left].back();
            a[left].pop_back();
            ans += (x + y) / k;
        }

    }
    rep(i, k) {
        while (!a[i].empty()) {
            ll x = a[i].back();
            a[i].pop_back();
            ans += x / k;
        }
    }
    print(ans)
}

void solve1() {
    int n, k; cin >> n >> k;
    vll a(n);
    ll ans = 0;
    rep(i, n) {
        ll x; cin >> x;
        ans += x / k;
        a[i] = x % k;
    }
    sort(a.begin(), a.end());
    int i = 0, j = n - 1;
    while (i < j) {
        if (a[i] + a[j] >= k) {
            j--;
            ans++;
        }
        i++;
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
        solve1();
    return 0;
}
