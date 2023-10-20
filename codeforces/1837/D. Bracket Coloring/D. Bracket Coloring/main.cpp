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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        int diff = 0;
        for (auto &c : s) {
            if (c == '(') diff++;
            else diff--;
        }
        if (diff != 0) {
            print(-1)
        } else {
            vector<int> res(n);
            int u = 0, v = 0;
            int cnt1 = 0, cnt2 = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == '(') {
                    if (v > 0) {
                        v--;
                        res[i] = 2;
                        cnt2++;
                    } else {
                        u++;
                        res[i] = 1;
                        cnt1++;
                    }
                } else {
                    if (u > 0) {
                        u--;
                        res[i] = 1;
                        cnt1++;
                    } else {
                        v++;
                        res[i] = 2;
                        cnt2++;
                    }
                }
            }
            if (cnt1 > 0 && cnt2 > 0) {
                print(2)
                printInline(res)
            } else {
                print(1)
                for (int i = 0; i < n; i++) {
                    res[i] = 1;
                }
                printInline(res)
            }
        }
    }
    return 0;
}
