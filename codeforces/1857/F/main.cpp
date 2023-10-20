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

long long my_sqrt(long long a)
{
    long long l=0,r=5000000001;
    while(r-l>1)
    {
        long long mid=(l+r)/2;
        if(1ll*mid*mid<=a)l=mid;
        else r=mid;
    }
    return l;
}

void solve() {
    int n; cin >> n;
    map<ll, ll> mp;
    // vll a(n); rep(i, n) cin >> a[i];
    rep(i, n) {
        ll x; cin >> x;
        mp[x]++;
    }
    int q; cin >> q;
    vll res;
    auto f = [&](ll b, ll c) -> ll {
        ll D = b * b - 4 * c;
        if (D < 0) return 0;
        ll x1 = (b + sqrtl(D)) / 2, x2 = (b - sqrtl(D)) / 2;
        if (x1 + x2 != b || x1 * x2 != c) return 0;
        if (D > 0) {
            return mp[x1] * mp[x2];
        } else if (D == 0) {
            return mp[x1] * (mp[x1] - 1) / 2;
        }
        return 0;
    };
    rep(i, q) {
        ll x, y; cin >> x >> y;
        ll cnt = f(x, y);
        res.push_back(cnt);
    }
    printInline(res)
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
