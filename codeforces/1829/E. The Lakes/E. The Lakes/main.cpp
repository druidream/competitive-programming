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

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};

int dfs(vector<vector<int>>& grid, int cur_i, int cur_j) {
    if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] == 0) {
        return 0;
    }
    int ans = grid[cur_i][cur_j];
    grid[cur_i][cur_j] = 0;
    for (int index = 0; index != 4; ++index) {
        int next_i = cur_i + di[index], next_j = cur_j + dj[index];
        ans += dfs(grid, next_i, next_j);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, 0));
        rep(i, n) {
            rep(j, m) {
                cin >> grid[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i != grid.size(); ++i) {
            for (int j = 0; j != grid[0].size(); ++j) {
                if (grid[i][j] == 0) continue;
                ans = max(ans, dfs(grid, i, j));
            }
        }
        print(ans)
    }
    return 0;
}
