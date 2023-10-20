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
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        // vector<pair<int, int>> arr(n);
        priority_queue<pair<int, int>> pq, on;
        rep(i, n) {
            int a, b; cin >> a >> b;
            // arr[i] = { a, b };
            pq.push({ -a, b });
        }
        ll x = 0, ans = 0;
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int a = abs(cur.first), b = cur.second;
            // if (a <= x) continue;
            ans += b;
            // cout << x << ' ' << a << ' ' << b << ' ' << ans << endl;
            x++;
            while (!pq.empty() && abs(pq.top().first) <= x) {
                pq.pop();
            }
            on.push({ -a, b });
            while (!on.empty() && abs(on.top().first) <= x) {
                on.pop();
                x--;
            }
        }
        print(ans)
    }
    return 0;
}
