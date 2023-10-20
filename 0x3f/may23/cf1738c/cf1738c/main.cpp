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

string solve() {
    int n; cin >> n;
    int even = 0, odd = 0;
    rep(i, n) {
        int x; cin >> x;
        if (x % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }
    if (odd % 4 == 0) { // 1 1 1 1 0
        return "Alice";
    } else if (odd % 4 == 1) { // 1, 1 0, 1 0 0
        return even % 2 == 0 ? "Bob" : "Alice";
    } else if (odd % 4 == 2) { // 1 1, 1 1 0, 1 1 0 0
        return "Bob";
    } else if (odd % 4 == 3) { // 1 1 1, 1 1 1 0, 1 1 1 0 0
        return "Alice";
    }
    return "Bob";
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
