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
        vi a(n); rep(i, n) cin >> a[i];
        
        
//        string s = "";
//        int beginPos = -1, endPos = -1;
//        for (int i = 0; i < n; i++) {
//            string x, y, z;
//            for (int j = i + 1; j < n; j++) {
//                z += to_string(a[j]);
//            }
//            for (int j = i; j >= 0; j--) {
//                y += to_string(a[j]);
//            }
//            if (z + y > s) {
//                s = z + y;
//                endPos = i;
//                beginPos = 0;
//            }
//            for (int j = 0; j < i; j++) {
//                string t = to_string(a[j]);
//                x += t;
//                int len = t.size();
//                while (len--) {
//                    y.pop_back();
//                }
//                t = z + y + x;
//                cout << i << ' ' << z << ' ' << y << ' ' << x << ' ' << endl;
//                if (t > s) {
//                    s = t;
//                    endPos = i;
//                    beginPos = j;
//                }
//            }
//        }
//
//        vi pre, suf, mid;
//        rep(i, n) {
//            string x, y, z;
//            if (i <= beginPos) {
//                pre.push_back(a[i]);
//            } else if (i <= endPos) {
//                mid.push_back(a[i]);
//            } else {
//                suf.push_back(a[i]);
//            }
//        }
//        reverse(mid.begin(), mid.end());
//        vi res;
//        rep(i, suf.size()) res.push_back(suf[i]);
//        rep(i, mid.size()) res.push_back(mid[i]);
//        rep(i, pre.size()) res.push_back(pre[i]);
//        printInline(res)
    }
    return 0;
}
