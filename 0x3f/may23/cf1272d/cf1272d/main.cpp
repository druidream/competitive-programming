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
#define read(n) int n; cin >> n;
#define readInts(a) vi a(n); rep(i, n) cin >> a[i];

double EPS = 1e-9;
int INF = 1000000005;
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
    int n; cin >> n;
    vi a(n); rep(i, n) cin >> a[i];
    vi l(n, 1), r(n, 1);
    int ans = 1;
    Rep(i, 1, n) {
        if (a[i] > a[i - 1]) l[i] = l[i - 1] + 1;
        ans = max(ans, l[i]);
        int j = n - 1 - i;
        if (a[j] < a[j + 1]) r[j] = r[j + 1] + 1;
    }
    for (int i = 1; i < n - 1; i++) {
        if (a[i - 1] < a[i + 1]) {
            ans = max(ans, l[i - 1] + r[i + 1]);
        }
    }
    print(ans)
    
    
    
    // WA
//    if (n == 2) {
//        int ans = (a[0] < a[1]) ? 2 : 1;
//        print(ans)
//        return 0;
//    }
//    vi b(n, 0);
//    int pre = 0, cnt = 0, ans = 0;
//    for (int i = 0; i < n; i++) {
//        if (a[i] > pre) {
//            cnt += 1;
//            b[i] = cnt;
//            ans = max(ans, cnt);
//        } else {
//            b[i - cnt] = cnt;
//            b[i] = 1;
//            cnt = 1;
//        }
//        pre = a[i];
//    }
//    if (cnt > 1) b[n - cnt] = cnt;
//    for (int i = 1; i < n - 1; i++) {
//        if (a[i] > a[i - 1] && a[i] >= a[i + 1] && a[i - 1] < a[i + 1]) {
//            ans = max(ans, b[i] + b[i + 1] - 1);
//        }
//    }
//    print(ans)
    return 0;
}
