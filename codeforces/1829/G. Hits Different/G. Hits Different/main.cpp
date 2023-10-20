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

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<ll>> f(1, vector<ll>());
    ll row = 0, cnt = row + 1, sum = 0;
    vector<ll> nums;
    for (ll i = 1; i <= 1e6; i++) {
        if (f[row].empty()) nums.push_back(i);
        sum += i * i;
        f[row].push_back(sum);
        cnt--;
        if (cnt == 0) {
            row++;
            cnt = row + 1;
            f.push_back(vector<ll>());
        }
    }
    int T; cin >> T;
    while (T--) {
        ll n; cin >> n;
        ll lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            if (nums[mid] > n) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        ll row = hi, col = n - nums[row], left = col;
        ll ans = 0;
        for (; row >= 0; row--) {
            col = min(col, (ll)f[row].size() - 1);
            ll pre = 0;
            if (left == 0) {
                pre = (row == 0) ? 0 : f[row - 1][row - 1];
            } else {
                pre = f[row][left - 1];
            }
            ans += f[row][col] - pre;
            if (left > 0) left--;
        }
        print(ans)
    }
    return 0;
}
