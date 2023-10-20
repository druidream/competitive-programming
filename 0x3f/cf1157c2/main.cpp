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

void solve() {
    int n; cin >> n;
    vi a(n); rep(i, n) cin >> a[i];
    int i = 0, j = n - 1;
    string s = "";
    int pre = 0;
    auto countLeft = [&](int i, int j, int pre) -> int {
        int cnt = 0;
        while (i <= j) {
            if (a[i] <= pre) {
                break;
            }
            cnt++;
            pre = a[i];
            i++;
        }
        return cnt;
    };
    auto countRight = [&](int i, int j, int pre) -> int {
        int cnt = 0;
        while (i <= j) {
            if (a[j] <= pre) {
                break;
            }
            cnt++;
            pre = a[j];
            j--;
        }
        return cnt;
    };
    while (i <= j) {
        if (pre >= a[i] && pre >= a[j]) {
            break;
        } else if (pre >= a[i]) {
            int cnt = countRight(i, j, pre);
            s += string(cnt, 'R');
            break;
        } else if (pre >= a[j]) {
            int cnt = countLeft(i, j, pre);
            s += string(cnt, 'L');
            break;
        } else {
            if (a[i] == a[j]) {
                int left = countLeft(i, j, pre), right = countRight(i, j, pre);
                // cout << left << ' ' << right << endl;
                if (left >= right) {
                    s += string(left, 'L');
                } else {
                    s += string(right, 'R');
                }
                break;
            } else if (a[i] < a[j]) {
                s += 'L';
                pre = a[i];
                i++;
            } else {
                s += 'R';
                pre = a[j];
                j--;
            }
        }
    }
    print(s.size())
    print(s)
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int T; cin >> T;
    // while (T--)
        solve();
    return 0;
}
