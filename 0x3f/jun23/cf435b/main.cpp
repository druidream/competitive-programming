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
    ll a; cin >> a;
    int k; cin >> k;
    string s = to_string(a);
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '9') continue;
        char mx = s[i];
        int pos = 0;
        for (int j = i + 1; j < min(n, i + 1 + k); j++) {
            if (s[j] > mx) {
                mx = s[j];
                pos = j;
            }
            if (mx == '9') break;
        }
        for (int j = pos; j > i; j--) {
            swap(s[j], s[j - 1]);
            k--;
        }
        if (k == 0) break;
    }
    print(s)
    return 0;
}
