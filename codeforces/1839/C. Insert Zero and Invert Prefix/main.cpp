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
        vi a(n); rep(i, n) cin >> a[i];
        if (a[n - 1] == 1) {
            print("NO")
            continue;
        }
        vi b;
        int cnt0 = 0, cnt1 = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] == 1) {
                cnt1++;
                if (i == 0 || a[i - 1] == 0) {
                    int p = cnt1;
                    while (cnt1 > 0) {
                        cnt1--;
                        b.push_back(0); 
                    }
                    while (cnt0 > 1) {
                        cnt0--;
                        b.push_back(0);
                    }
                    b.push_back(p);
                    cnt0--;
                }
            } else {
                cnt0++;
                if (i == 0) {
                    while (cnt0 > 0) {
                        cnt0--;
                        b.push_back(0);
                    }
                }
            }
        }
        print("YES")
        printInline(b)
    }
    return 0;
}
