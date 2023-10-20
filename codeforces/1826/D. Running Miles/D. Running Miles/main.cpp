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

struct cmp {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return a.first + a.second > b.first + b.second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vi a(n); rep(i, n) cin >> a[i];
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        pq.push({ a[0], 0 });
        pq.push({ a[1], 1 });
        int ans = 0;
        for (int i = 2; i < n; i++) {
            pq.push({ a[i], i });
            if (pq.size() > 3) pq.pop();
            auto p1 = pq.top(); pq.pop();
            auto p2 = pq.top(); pq.pop();
            auto p3 = pq.top(); pq.pop();
            int sum = p1.first + p2.first + p3.first;
            int mn = min(p1.second, min(p2.second, p3.second));
            ans = max(ans, sum - (i - mn));
//            cout << i << ' ' << ans << endl;
            pq.push(p1);
            pq.push(p2);
            pq.push(p3);
        }
        print(ans)
    }
    return 0;
}
