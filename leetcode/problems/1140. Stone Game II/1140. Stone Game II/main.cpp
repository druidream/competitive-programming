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

// AC
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        int tot = 0;
        for (auto &x : piles) tot += x;
        function<int(int, int)> dfs = [&](int x, int m) -> int {
            if (x == n) return 0;
            int sum = 0;
            int res = INT_MIN;
            for (int i = x; i <= min(n - 1, x + m * 2 - 1); i++) {
                sum += piles[i];
                res = max(res, sum - dfs(i + 1, max(m, i - x + 1)));
            }
            return res;
        };
        int diff = dfs(0, 1);
        return (tot + diff) / 2;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vi piles = { 2,7,9,4,4 };
    int ans = Solution().stoneGameII(piles);
    print(ans)
    return 0;
}

