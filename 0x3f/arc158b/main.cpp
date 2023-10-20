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
const int mod = 998244353;
int d4[5] = { 0, 1, 0, -1, 0 };

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;

void solve() {
    int n; cin >> n;
    vll a(n); rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    int negCnt = 0, posCnt = 0;
    rep(i, n) {
        if (a[i] < 0) negCnt++;
        else posCnt++;
    }
    long double mn = 3, mx = -3;
    auto f = [&](int i, int j, int k) -> long double {
        auto ans = (long double)(a[i] + a[j] + a[k]) / (long double)(a[i] * a[j] * a[k]);
        // cout << i << ' ' << j << ' ' << k << ' ' << ans << endl;
        return ans;
    };
    auto neg3pos0 = [&]() -> pair<long double, long double> {
        auto a = f(0, 1, 2); // mn
        auto b = f(negCnt - 1, negCnt - 2, negCnt - 3); // mx
        return { a, b };
    };
    auto neg2pos1 = [&]() -> pair<long double, long double> {
        long double a = 3, b = -3;
        for (int j = 1; j < negCnt; j++) { // enumerate j
            auto x = f(0, j, negCnt);
            // cout << "x: " << x << endl;
            a = min(a, x);
            b = max(b, x);
            auto y = f(0, j, n - 1);
            // cout << "y: " << y << endl;
            a = min(a, y);
            b = max(b, y);
            auto z = f(j - 1, j, negCnt);
            // cout << "z: " << z << endl;
            a = min(a, z);
            b = max(b, z);
            auto w = f(j - 1, j, n - 1);
            // cout << "w: " << w << endl;
            a = min(a, w);
            b = max(b, w);
        }
        return { a, b };
    };
    auto neg1pos2 = [&]() -> pair<long double, long double> {
        long double a = 3, b = -3;
        for (int j = negCnt; j < n - 1; j++) { // enumerate j
            auto x = f(0, j, n - 1);
            a = min(a, x);
            b = max(b, x);
            auto y = f(0, j, j + 1);
            a = min(a, y);
            b = max(b, y);
            auto z = f(negCnt - 1, j, n - 1);
            a = min(a, z);
            b = max(b, z);
            auto w = f(negCnt - 1, j, j + 1);
            a = min(a, w);
            b = max(b, w);
        }
        return { a, b };
    };
    auto neg0pos3 = [&]() -> pair<long double, long double> {
        long double b = f(negCnt, negCnt + 1, negCnt + 2);
        long double a = f(n - 1, n - 2, n - 3);
        return { a, b };
    };
    if (negCnt >= 3 && posCnt >= 0) {
        auto [a, b] = neg3pos0();
        mn = min(mn, a);
        mx = max(mx, b);
    }
    if (negCnt >= 2 && posCnt >= 1) {
        auto [a, b] = neg2pos1();
        mn = min(mn, a);
        mx = max(mx, b);
    }
    if (negCnt >= 1 && posCnt >= 2) {
        auto [a, b] = neg1pos2();
        mn = min(mn, a);
        mx = max(mx, b);
    }
    if (negCnt >= 0 && posCnt >= 3) {
        auto [a, b] = neg0pos3();
        mn = min(mn, a);
        mx = max(mx, b);
    }
    cout << fixed << setprecision(15) << mn << '\n' << mx << '\n';
}

void solve1() {
    int n; cin >> n;
    vll a(n); rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    int negCnt = 0, posCnt = 0;
    rep(i, n) {
        if (a[i] < 0) negCnt++;
        else posCnt++;
    }
    vll arr;
    int i = 0, j = negCnt - 1, t = 3;
    while (i <= j && t > 0) {
        arr.push_back(a[i]);
        if (i != j) arr.push_back(a[j]);
        i++;
        j--;
        t--;
    }
    i = negCnt; j = n - 1; t = 3;
    while (i <= j && t > 0) {
        arr.push_back(a[i]);
        if (i != j) arr.push_back(a[j]);
        i++;
        j--;
        t--;
    }

    auto f = [&](int i, int j, int k) -> long double {
        auto ans = (long double)(arr[i] + arr[j] + arr[k]) / (long double)(arr[i] * arr[j] * arr[k]);
        // cout << i << ' ' << j << ' ' << k << ' ' << ans << endl;
        return ans;
    };
    long double mn = 3, mx = -3;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            for (int k = j + 1; k < arr.size(); k++) {
                auto x = f(i, j, k);
                mn = min(mn, x);
                mx = max(mx, x);
            }
        }
    }
    cout << fixed << setprecision(15) << mn << '\n' << mx << '\n';
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        solve1();
    return 0;
}
