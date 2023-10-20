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

    int n, q; cin >> n >> q;
    string s; cin >> s;
    // vi qs(q); rep(i, q) cin >> qs[i];
    if (n % 2 == 1) {
        rep(i, q) {
            int x; cin >> x;
            print("No")
        }
        return 0;
    }
    vi a(n, 0);
    int x = n, y = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            if (x == -1 && i > 0 && s[i] == s[i - 1]) x = i;
        } else {
            if (y == -1 && i < n - 1 && s[i] == s[i + 1]) y = i;
        }
    }
    int d = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            d++;
        } else {
            d--;
        }
        a[i] = d;
    }
    vector<bool> b(n, false);
    for (int i = 0; i < n; i++) {
        int t = a[i];
        if (i > x && i < y) {
            b[i] = true;
        } else if (i <= x) {
            if (s[i] == '(') {
                b[i] = a[i] - 2 > 0;
            } else {
                b[i] = true;
            }
        } else if (i >= y) {
            if (s[i] == ')') {
                b[i] = a[i] + 2 < 0;
            } else {
                b[i] = true;
            }
        }
    }

    rep(i, q) {
        int x; cin >> x;
        cout << (b[x - 1] ? "YES" : "NO") << '\n';
    }

    return 0;
}
