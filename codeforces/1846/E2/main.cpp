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

set<ll> nums;

void preprocess() {
    // for (ll k = 2; k <= 1e6; k++) {
    //     ll p = k * k, tot = 1 + k + p;
    //     while (true) {
    //         nums.insert(tot);
    //         if (1e18 / k < p) break;
    //         p *= k;
    //         tot += p;
    //         if (tot > 1e18) break;
    //     }
    // }

    for (ll k = 2; k <= 1e6; k++) {
        ll sum = 1 + k, cur = k * k;
        while (sum + cur <= 1e18) {
            sum += cur;
            nums.insert(sum);
            if (1e18 / k < cur) break;
            cur *= k;
        }
    }
}

void solve() {
    ll n; cin >> n;
    bool ans = false;
    if (nums.find(n) != nums.end()) {
        ans = true;
    }
    if (ans) {
        printBool(ans)
        return;
    }
    ll a = 1, b = 1, c = 1 - n;
    ll delta = b * b - 4 * a * c;
    if (delta >= 0) {
        ll root = sqrtl(delta);
        // cout << root << ' ' << delta << endl;
        if (root * root == delta && ((root - b) % 2 == 0) && (root - b) / 2 > 1) {
            // cout << (root - b) / 2 << endl;
            ans = true;
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
    preprocess();
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
