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

// void solve() {
//     int k; cin >> k;
//     // if (k <= 10) {
//     //     print(k)
//     //     return;
//     // }
//     // k -= 10;
//     vector<vector<vector<int>>> memo(10, vector<vector<int>>(10, vector<int>(10, -1)));
//     function<int(int, int, int)> dfs = [&](int cur, int pre, int len) -> int {
//         if (cur == len) {
//             return 1;
//         }
//         if (memo[cur][pre][len] != -1) return memo[cur][pre][len];
//         int res = 0;
//         for (int y = 0; y < pre; y++) {
//             res += dfs(cur + 1, y, len);
//         }
//         memo[cur][pre][len] = res;
//         return res;
//     };
//     // int tot = 0;
//     vi f(10);
//     f[0] = 9;
//     for (int len = 2; len <= 10; len++) {
//         int cnt = 0;
//         for (int x = 0; x <= 9; x++) {
//             cnt += dfs(1, x, len);
//         }
//         // print(cnt)
//         // tot += cnt;
//         f[len - 1] = cnt;
//     }
//     // printInline(f)
//     int len = 1;
//     for (int i = 0; i < 10; i++) {
//         if (k - f[i] >= 0) {
//             k -= f[i];
//             len++;
//         } else {
//             break;
//         }
//     }
//     string s(len, '0');
//     for (int j = len - 2; j >= 0; j--) {
//         s[j] = s[j + 1] + 1;
//     }
//     // print(s)
//     k--;
//     while (k--) {
//         int m = s.size();
//         s[m - 1]++;
//         // cout << s << ' ' << k << endl;
//         for (int i = m - 1; i > 0; i--) {
//             if (s[i] == s[i - 1]) {
//                 if (i == m - 1) {
//                     s[i] = '0';
//                 } else {
//                     s[i] = s[i + 1] + 1;
//                 }
//                 s[i - 1]++;
//             }
//         }
//     }
//     print(s)
// }

// void solve1() {
//     int k; cin >> k;
//     vi f(10);
//     f[0] = 9;
//     vector<vector<vector<int>>> memo(10, vector<vector<int>>(10, vector<int>(10, -1)));
//     function<int(int, int, int)> dfs = [&](int cur, int pre, int len) -> int {
//         if (cur == len) {
//             return 1;
//         }
//         if (memo[cur][pre][len] != -1) return memo[cur][pre][len];
//         int res = 0;
//         for (int y = 0; y < pre; y++) {
//             res += dfs(cur + 1, y, len);
//         }
//         memo[cur][pre][len] = res;
//         return res;
//     };
//     for (int len = 2; len <= 10; len++) {
//         int cnt = 0;
//         for (int x = 0; x <= 9; x++) {
//             cnt += dfs(1, x, len);
//         }
//         f[len - 1] = cnt;
//     }
//     vi g(11);
//     rep(i, 10) {
//         g[i + 1] = g[i] + f[i];
//     }

//     auto check = [&](ll x) -> bool {
//         string s = to_string(x);
//         int m = s.size();

//         vector<vector<vector<int>>> memo(10, vector<vector<int>>(10, vector<int>(10, -1)));
//         function<int(int, int, int, bool)> dfs1 = [&](int cur, int pre, int len, bool isLimit) -> int {
//             if (cur == len) {
//                 return 1;
//             }
//             if (!isLimit && memo[cur][pre][len] != -1) return memo[cur][pre][len];
//             int res = 0;
//             int up = isLimit ? s[cur] - '0' : 9;
//             for (int y = 0; y < min(pre, up); y++) {
//                 res += dfs1(cur + 1, y, len, isLimit && y == up);
//             }
//             if (!isLimit) memo[cur][pre][len] = res;
//             return res;
//         };

//         int cnt = g[m - 1];
//         for (int x = 0; x <= 9; x++) {
//             cnt += dfs1(1, x, m, true);
//         }
        
//         return cnt <= k;
//     };
//     ll lo = 1, hi = 987654321;
//     while (lo <= hi) {
//         ll mid = (lo + hi) / 2;
//         if (check(mid)) {
//             lo = mid + 1;
//         } else {
//             hi = mid - 1;
//         }
//     }
//     print(hi)
// }

void solve2() {
    int k; cin >> k;
    vector<ll> arr;
    for (int mask = 1; mask < (1 << 10); mask++) {
        ll v = 0;
        for (int i = 0; i < 10; i++) {
            if ((mask >> i) & 1) {
                v = v * 10 + (9 - i);
            }
        }
        arr.push_back(v);
    }
    sort(arr.begin(), arr.end());
    // printInline(arr)
    print(arr[k])
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
        solve2();
    return 0;
}
