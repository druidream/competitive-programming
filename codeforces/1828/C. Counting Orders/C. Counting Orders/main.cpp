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
int mod = 1e9 + 7;

ll solve() {
    int n; cin >> n;
    vi a(n); rep(i, n) cin >> a[i];
    vi b(n); rep(i, n) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll j = 0, ans = 1;
    rep(i, n) {
        while (j < n && a[i] > b[j]) j++;
        ll cnt = j - i;
        if (cnt <= 0) return 0;
        ans = (ans * cnt) % mod;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    while (T--) {
        print(solve())
    }
    return 0;
}
