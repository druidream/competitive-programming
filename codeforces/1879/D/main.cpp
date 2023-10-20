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
    vll a(n); rep(i, n) cin >> a[i];
    ll ans = 0;
    for (int j = 0; j < 31; j++) {
        map<int, ll> mp;
        mp[0] = -1;
        ll cnt0 = 1, cnt1 = 0, bit = 0;
        ll v = 0;
        rep(i, n) {
            bit ^= (a[i] >> j) & 1;
            // cout << "i: " << i << ' ' << v << ' ' << cnt0 << ' ' << cnt1 << endl;
            if (bit == 1) {
                if (mp.find(bit ^ 1) != mp.end()) {
                    v = (v + cnt0 * (i) - mp[bit ^ 1]) % mod;    
                }
                cnt1++;
                mp[1] += i;
            } else {
                if (mp.find(bit ^ 1) != mp.end()) {
                    v = (v + cnt1 * (i) - mp[bit ^ 1]) % mod;    
                }
                cnt0++;
                mp[0] += i;
            }
        }
        ans = (ans + v * (1 << j)) % mod;
        // cout << j << ' ' << ans << endl;
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
