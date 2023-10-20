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

map<int, pair<int, int>> mp;

bool solve() {
    int n; cin >> n;
    ll tot = 0;
    vll a(n); 
    rep(i, n) {
        cin >> a[i];
        tot += a[i];
    }
    if (tot % n != 0) {
        return false;
    }
    // print(tot)
    ll avg = tot / n;
    // vector<int> f(32);
    // int cnt = 0;
    // rep(i, n) {
    //     if (a[i] == avg) {
    //         cnt++;
    //         continue;
    //     }
    //     int in = -1, out = -1;
    //     rep(j, 32) {
    //         ll u = (a[i] >> j) & 1, v = (avg >> j) & 1;

    //         if (u == v) continue;
    //         if (u == 1) {
    //             if (out != -1) return false;
    //             out = j;
    //         }
    //         if (v == 1) {
    //             if (in != -1) return false;
    //             in = j;
    //         }
    //     }
    //     // if (in == -1 || out == -1) return false;
    //     if (out != -1) f[out]++;
    //     if (in != -1) f[in]--;
    // }

    // WA
    // sort(a.begin(), a.end());
    // map<ll, int> out_mp, in_mp;
    // for (int i = 0; i < n; i++) {
    //     ll diff = abs(avg - a[i]);
    //     int bitcount = __builtin_popcount(diff);
    //     if (bitcount > 2) {
    //         return false;
    //     } else if (bitcount == 2) {
    //         int in = -1, out = -1;
    //         rep(j, 32) {
    //             ll u = (a[i] >> j) & 1, v = (avg >> j) & 1;
    //             if (u == v) continue;
    //             if (u == 1 && v == 0) {
    //                 if (out != -1) return false;
    //                 out = j;
    //             }
    //             if (u == 0 && v == 1) {
    //                 if (in != -1) return false;
    //                 in = j;
    //             }
    //         }
    //         out_mp[1 << out]++;
    //         in_mp[1 << in]++;
    //     } else if (bitcount == 1) {
    //         if (a[i] > avg) {
    //             ll out = diff * 2;
    //             ll in = diff;
    //             out_mp[out]++;
    //             in_mp[in]++;
    //         } else {
    //             ll out = diff;
    //             ll in = diff * 2;
    //             out_mp[out]++;
    //             in_mp[in]++;
    //         }
    //     }
    // }
    // if (out_mp.size() != in_mp.size()) return false;
    // for (auto [k, v] : out_mp) {
    //     if (in_mp[k] != v) return false;
    // }
    // return true;
    ll s = avg;
    vi cnt(32);
    rep(i, n) {
        if (a[i] == s) continue;
        int diff = abs(a[i] - s);
        if (mp.find(diff) == mp.end()) return false;
        auto p = mp[diff];
        if (a[i] > s) {
            cnt[p.first]++;
            cnt[p.second]--;
        } else {
            cnt[p.second]++;
            cnt[p.first]--;
        }
    }
    bool ans = true;
    rep(i, 32) {
        if (cnt[i] != 0) ans = false;
    }
    return ans;
}

void prepare() {
    for (int i = 0; i < 31; i++) {
        for (int j = 0; j < i; j++) {
            int k = (1 << i) - (1 << j);
            mp[k] = { i, j };
        }
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
    cin >> T;
    prepare();
    while (T--) {
        bool ans = solve();
        printBool(ans)
    }
    return 0;
}
