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

void solve(int caseId) {
    int n; cin >> n;
    int s = 0, ad = 0, ads = 0;
    int sa = 0, d = 0, dsa = 0;
    int a = 0;
    int sad = 0;
    int lastS = 0, firstD = 0, ds = 0;
    rep(i, n) {
        string S; cin >> S;
        int m = S.size();
        for (int i = 2; i < S.size(); i++) {
            if (S[i - 2] == 'S' && S[i - 1] == 'A' && S[i] == 'D') sad++;
        }
        if (m >= 3 && S[m - 1] == 'S' && S[0] == 'A' && S[1] == 'D') {
            ads++;
        } else if (m >= 2 && S[0] == 'A' && S[1] == 'D') {
            ad++;
        } else if (S[m - 1] == 'S') {
            s++;
        }
        if (m >= 3 && S[m - 2] == 'S' && S[m - 1] == 'A' && S[0] == 'D') {
            dsa++;
        } else if (m >= 2 && S[m - 2] == 'S' && S[m - 1] == 'A') {
            sa++;
        } else if (S[0] == 'D') {
            d++;
        }
        if (S == "A") a++;
        if (m >= 2 && S[0] == 'D' && S[m - 1] == 'S') ds++;
        else if (S[0] == 'D') firstD++;
        else if (S[m - 1] == 'S') lastS++;
        
    }
    cout << firstD << ' ' << lastS << endl;
    int adsCnt = ads + min(s, ad);
    int dsaCnt = dsa + min(sa, d);
    if (ads > 0 && s == 0 && ad == 0) adsCnt--;
    if (dsa > 0 && sa == 0 && d == 0) dsaCnt--;

    int ans = sad + adsCnt + dsaCnt;
    lastS -= adsCnt;
    firstD -= dsaCnt;
    cout << adsCnt << ' ' << dsaCnt << endl;;
    int dasCnt = ds + min(lastS, firstD);
    if (ds > 0 && a > 0 && lastS == 0 && firstD == 0) dasCnt--;
    ans += min(a, dasCnt);
    cout << ds << ' ' << a << ' ' << lastS << ' ' << firstD << endl;
    cout << "Case #" << caseId << ": " << ans << '\n';
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    int caseId = 0;
    while (T--)
        solve(++caseId);
    return 0;
}
