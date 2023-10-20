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
class EraseThird {
    public:
    // vector<string> erase(string S) {
    //     int n = S.size();
    //     vector<string> res(26, "NO");
    //     if (n == 0) {
    //         return res;
    //     } else if (n == 1) {
    //         res[S[0] - 'a'] = "";
    //         return res;
    //     }
            
    //     int X = roundUp(n, 3);
    //     string a = S.substr(0, X), b = S.substr(X, n - X - X), c = S.substr(n - X);
    //     cout << a << ' ' << b << ' ' << c << endl;
    //     vector<string> u = erase(a), v = erase(b), w = erase(c);
    //     for (int i = 0; i < 26; i++) {
    //         if (u[i] != "NO") {
    //             res[i] = "1" + u[i];
    //         } else if (v[i] != "NO") {
    //             res[i] = "2" + v[i];
    //         } else if (w[i] != "NO") {
    //             res[i] = "3" + w[i];
    //         }
    //     }
    //     return res;
    // }
    vector<string> erase(string s) {
        int n = s.size();
        vector<string> res(26, "NO");
        vector<int> pos(26, -1);
        for (int i = 0; i < n; i++) {
            pos[s[i] - 'a'] = i;
        }
        function<string(int, int, int)> check = [&](int k, int l, int r) -> string {
            if (l == r) return "";
            int len = r - l + 1, a = roundUp(len, 3);
            if (pos[k] >= l + a) {
                return "1" + check(k, l + a, r);
            } else {
                return "3" + check(k, l, r - a);
            }
        };
        rep(k, 26) {
            if (pos[k] != -1) res[k] = check(k, 0, n - 1);
        }   
        return res;
    }
};

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    while (T--) {
        EraseThird obj = EraseThird();
        string s; cin >> s;
        vector<string> t = obj.erase(s);
        printInline(t)
    }
}