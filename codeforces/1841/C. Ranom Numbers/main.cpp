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

double EPS = 1e-9;
int INF = 0x3f3f3f3f;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    vi a = { 1, 10, 100, 1000, 10000 };
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int n = s.size();
        vector<vector<vector<int>>> memo(n + 1, vector<vector<int>>(2, vector<int>(5, -1)));
        function<int(int, int, int)> dfs = [&](int pos, int isModified, int mx) -> ll {
            // cout << pos << ' ' << isModified << ' ' << mx << ' ' << sum << endl;
            if (pos < 0) return 0;
            if (memo[pos][isModified][mx] != -1) return memo[pos][isModified][mx];
            ll res = -INF;

            char c = s[pos];
            ll u = a[c - 'A'];
            if (c - 'A' < mx) u = -u;
            ll v = dfs(pos - 1, isModified, max(mx, c - 'A'));
            // cout << pos << ' ' << v << endl;
            res = max(res, v + u);

            if (!isModified) {
                for (int i = 0; i < 5; i++) {
                    char c = i + 'A';
                    ll u = a[c - 'A'];
                    if (c == s[pos]) {
                        continue;
                    } else {
                        if (i < mx) {
                            u = -u;
                        }
                        ll v = dfs(pos - 1, 1, max(mx, i));
                        // cout << c << ' ' << v << ' ' << endl;
                        res = max(res, v + u);
                    }
                }
            }
            memo[pos][isModified][mx] = res;
            return res;
        };
        ll ans = dfs(n - 1, 0, 0);
        print(ans)
    }
    return 0;
}
