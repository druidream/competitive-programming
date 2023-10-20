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
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
	#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    int k = n / 3;
    int a = 0, b = 0, c = 0;
    rep(i, n) {
        if (s[i] == '0') a++;
        if (s[i] == '1') b++;
        if (s[i] == '2') c++;
    }
    rev(i, n) {
        if (s[i] == '0' && a > k) {
            if (c < k) {
                s[i] = '2';
                a--; c++;
            } else if (b < k) {
                s[i] = '1';
                a--; b++;
            }
        }
        if (s[i] == '1' && b > k) {
            if (c < k) {
                s[i] = '2';
                c++; b--;
            // } else {
            //     s[i] = '0';
            //     a++; b--;
            }
        }
    }
    rep(i, n) {
        if (s[i] == '2' && c > k) {
            if (a < k) {
                s[i] = '0';
                a++; c--;
            } else if (b < k) {
                s[i] = '1';
                b++; c--;
            }
        }
        if (s[i] == '1' && b > k) {
            if (a < k) {
                s[i] = '0';
                a++; b--;
            } else {
                s[i] = '2';
                c++; b--;
            }
        }
    }
    print(s)
    return 0;
}
