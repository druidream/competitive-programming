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
    int T; cin >> T;
    while (T--) {
        ll n, k; cin >> n >> k;
        string s; cin >> s;
        ll cnt = 0;
        rep(i, n) {
            if (s[i] == '1') {
                cnt += 1;
            } else {
                ll kk = min(k, cnt);
                k -= kk;
//                swap(s[i], s[i - kk]);
                s[i] = '1';
                s[i - kk] = '0';
                if (k == 0) {
                    break;
                }
            }
        }
        print(s)
    }
    return 0;
}
