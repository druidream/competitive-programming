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
        string s, t; cin >> s >> t;
        vector<string> arr = { s, t };
        set<int> diff;
        rep(i, s.size()) {
            if (s[i] != t[i]) {
                diff.insert(i);
            }
        }
        deque<pair<int, int>> block;
        int k, q; cin >> k >> q;
        rep(i, q) {
            int type; cin >> type;
            if (type == 1) {
                int pos; cin >> pos;
                block.push_back({ i + k - 1, pos - 1 });
            } else if (type == 2) {
                int n1, pos1, n2, pos2; cin >> n1 >> pos1 >> n2 >> pos2;
                n1--; n2--; pos1--; pos2--;
                if (arr[n1][pos1] == arr[n2][pos2]) continue;
                if (arr[n1][pos1] != arr[n1 ^ 1][pos1]) diff.erase(pos1);
                if (arr[n2][pos2] != arr[n2 ^ 1][pos2]) diff.erase(pos2);
                char a = arr[n1][pos1], b = arr[n2][pos2];
                arr[n1][pos1] = b;
                arr[n2][pos2] = a;
                if (arr[n1][pos1] != arr[n1 ^ 1][pos1]) diff.insert(pos1);
                if (arr[n2][pos2] != arr[n2 ^ 1][pos2]) diff.insert(pos2);
            } else {
                while (!block.empty() && block.front().first < i) {
                    block.pop_front();
                }
                // cout << block.size() << endl;
                // if (block.size() == 4) {
                //     for (auto d : diff) {
                //         cout << d;
                //     }
                //     cout << endl;
                //     cout << block[0].second << block[1].second << block[2].second << endl;
                // }
                int cnt = 0;
                for (int i = 0; i < block.size(); i++) {
                    if (diff.find(block[i].second) != diff.end()) {
                        cnt++;
                    }
                }
                bool ans = cnt == diff.size();
                printBool(ans)
            }
        }
    }
    return 0;
}
