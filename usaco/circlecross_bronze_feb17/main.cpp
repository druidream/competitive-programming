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

#define debugMap(mp) cout << "map: \n"; for (auto &kv : mp) cout << kv.first << ' ' << kv.second << '\n'; cout << "-----" << endl;
#define debugStack(st) cout << "stack: "; while (st.size()) { cout << st.top() << ' '; st.pop(); } cout << '\n';

double EPS = 1e-9;
int INF = 0x3f3f3f3f;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};
// const int mod = 998244353;
int d4[5] = { 0, 1, 0, -1, 0 };

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;

void solve() {
    string s; cin >> s;
    vi a(26, -1), b(26, -1);
    for (int i = 0; i < 52; i++) {
        auto c = s[i] - 'A';
        if (a[c] == -1) {
            a[c] = i;
        } else {
            b[c] = i;
        }
    }
    // printInline(a)
    // printInline(b)
    // AABB
    // ABBA
    // ABAB <-
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < i; j++) {
            vector<int> arr = { a[i], a[j], b[i], b[j] };
            sort(arr.begin(), arr.end());
            if ((arr[0] == a[i] && arr[2] == b[i]) || (arr[1] == a[i] && arr[3] == b[i])) ans++;
        }
    }
    print(ans)
}

void solve1() {
    // count the number of times a single letter appears between two other letters
    string s; cin >> s;
    vi a(26, -1), b(26, -1);
    for (int i = 0; i < 52; i++) {
        auto c = s[i] - 'A';
        if (a[c] == -1) {
            a[c] = i;
        } else {
            b[c] = i;
        }
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        int mask = 0;
        for (int pos = a[i] + 1; pos < b[i]; pos++) {
            if (s[pos] < s[a[i]]) continue; // prevent repeat
            mask ^= 1 << (s[pos] - 'A');
        }
        ans += __builtin_popcount(mask);
    }
    print(ans)
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        solve1();
    return 0;
}
