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
    string t; cin >> t;
    vector<string> S(n); rep(i, n) cin >> S[i];
    int m = t.size();
    auto isAdd = [&](string s) -> bool {
        // return false;
        if (s.size() != m - 1) return false;
        // int j = 0;
        // bool hasDiff = false;
        // for (int i = 0; i < m - 1; i++) {
        //     if (s[i] == t[j]) {
        //         j++;
        //     } else {
        //         if (hasDiff) return false;
        //         hasDiff = true;
        //         j += 2;
        //     }
        // }
        // hasDiff += j == m - 1;
        // return hasDiff == 1;
        int i = 0, j = m - 1;
        int cnt = 0;
        while (i < m) {
            if (s[i] == t[i]) {
                cnt++;
                i++;
            }
            else break;
        }
        while (j > i) {
            if (s[j - 1] == t[j]) cnt++;
            else break;
            j--;
        }
        // cout << cnt << m << endl;
        return cnt == m - 1;
    };
    auto isDelete = [&](string s) -> bool {
        // return false;
        if (s.size() != m + 1) return false;
        // bool hasDiff = false;
        // int j = 0;
        // for (int i = 0; i < m; i++) {
        //     if (s[i] == t[j]) {
        //         j++;
        //     } else {
        //         if (hasDiff) return false;
        //         hasDiff = true;
        //     }
        // }
        // return hasDiff;
        int i = 0, j = m - 1;
        int cnt = 0;
        // cout << s << ' ' << t << endl;
        // cout << cnt << m << endl;
        while (i < m) {
            // cout << s[i] << ' ' << t[i] << endl;
            if (s[i] == t[i]) {
                cnt++;
                i++;
            }
            else break;
        }
        // cout << cnt << m << endl;
        while (j >= i) {
            if (s[j + 1] == t[j]) cnt++;
            else break;
            j--;
        }
        // cout << cnt << m << endl;
        return cnt == m;
    };
    auto isChange = [&](string s) -> bool {
        // return false;
        if (s.size() != m) return false;
        // bool hasDiff = false;
        // for (int i = 0; i < m; i++) {
        //     if (s[i] != t[i]) {
        //         if (!hasDiff) hasDiff = true;
        //         else return false;
        //     }
        // }
        // return hasDiff;
        int i = 0, j = m - 1;
        int cnt = 0;
        while (i < m) {
            if (s[i] == t[i]) {
                cnt++;
                i++;
            } 
            else break;
        }
        while (j >= i) {
            if (s[j] == t[j]) cnt++;
            else break;
            j--;
        }
        return cnt == m - 1;
    };

    vi res;
    rep(i, n) {
        string s = S[i];
        if (s == t) {
            // print(1)
            res.push_back(i + 1);
        } else if (isAdd(s)) {
            // print(2)
            res.push_back(i + 1);
        } else if (isDelete(s)) {
            // print(3)
            res.push_back(i + 1);
        } else if (isChange(s)) {
            // print(4)
            res.push_back(i + 1);
        }
    }
    // print(res.size())
    // printInline(res)
    cout << res.size() << '\n';
    for (auto &x : res) {
        cout << x << ' ';
    }
    cout << '\n';
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
