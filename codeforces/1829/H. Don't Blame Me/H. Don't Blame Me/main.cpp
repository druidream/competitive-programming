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
    int mod = 1e9 + 7;
    
    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        vi a(n); rep(i, n) cin >> a[i];
        map<int, int> mp;
        int ans = 0;
        rep(i, n) {
            int bit = __builtin_popcount(a[i]);
            if (bit < k) continue;
            for (auto& kv : mp) {
                int u = kv.first & a[i];
                int bitcount = __builtin_popcount(u);
                if (bitcount < k) continue;
                if (bitcount == k) {
                    ans = (ans + kv.second) % mod;
                }
                mp[u] = (mp[u] + kv.second) % mod;
            }
            if (bit == k) {
                ans++;
            }
            mp[a[i]] = (mp[a[i]] + 1) % mod;
        }
        print(ans % mod)
    }
    return 0;
}
