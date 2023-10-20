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

// TLE
// void solve() {
//     string s; cin >> s;
//     int n = s.size();
//     vi f(n + 1, -1);
//     f[0] = 1; f[1] = 1;
//     int len = 0;
//     bool ans = true;
//     for (auto &c : s) {
//         if (c == '+') {
//             if (f[len] == 0) f[len + 1] = 0;
//             len++;
//         }
//         if (c == '-') {
//             if (len > 1) f[len] = -1;
//             len--;
//         }
//         if (c == '1') {
//             if (f[len] == 0) {
//                 ans = false;
//                 break;
//             }
//             f[len] = 1;
//             // for (int i = len - 1; i > 1; i--) {
//                 if (f[len - 1] == -1) f[len - 1] = 1;
//             // }
//         } else if (c == '0') { 
//             // print(len)
//             if (f[len] == 1) {
//                 ans = false;
//                 break;
//             }
//             f[len] = 0;
//         }
//         // printInline(f)
//     }
//     printBool(ans)
// }

// https://www.youtube.com/watch?v=xhrQ1MzxfhU
void solve() {
    string s; cin >> s;
    int cur = 0;
    int maxSorted = 0;
    int minNotSorted = INF;
    bool ans = true;
    for (auto &c : s) {
        if (c == '+') {
            cur++;
        } else if (c == '-') {
            cur--;
            if (minNotSorted > cur) minNotSorted = INF;
            maxSorted = min(maxSorted, cur);
        } else if (c == '1') {
            // should not have a prefix that is not sorted
            if (minNotSorted <= cur) {
                ans = false;
                break;
            }
            maxSorted = max(maxSorted, cur);
        } else {
            // subarray of a sorted array should also be sorted
            if (maxSorted >= cur || cur <= 1) {
                ans = false;
                break;
            }
            minNotSorted = min(minNotSorted, cur);
        }
    }
    printBool(ans)
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
