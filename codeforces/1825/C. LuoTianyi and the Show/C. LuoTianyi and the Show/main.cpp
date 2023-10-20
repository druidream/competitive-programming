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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        vi a;
        int left = 0, right = 0;
        set<int> seen;
        rep(i, n) {
            int x; cin >> x;
            if (x == -1) left++;
            if (x == -2) right++;
            if (x > 0 && (seen.find(x) == seen.end())) {
                a.push_back(x);
                seen.insert(x);
            }
        }
        sort(a.begin(), a.end());
        int len = a.size();
        int ans = 0;
        for (int i = 0; i < a.size(); i++) {
            int l = min(i + left, a[i] - 1);
            int r = min(len - i - 1 + right, m - a[i]);
            ans = max(ans, l + r + 1);
        }
        ans = max(ans, min(m, left + len)); // only left
        ans = max(ans, min(m, right + len)); // only right
        print(ans)
    }
    return 0;
}
