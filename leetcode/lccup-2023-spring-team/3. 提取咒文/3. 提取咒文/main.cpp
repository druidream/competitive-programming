#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int extractMantra(vector<string>& mat, string mantra) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<pair<int, int>>> arr(26, vector<pair<int, int>>());
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int idx = mat[i][j] - 'a';
                arr[idx].push_back({ i, j });
            }
        }
        char pre = ' ';
        int rep = 0;
        string s = "";
        for (auto c : mantra) {
            int idx = c - 'a';
            if (arr[idx].empty()) { return -1; }
            if (c == pre) {
                rep += 1;
            } else {
                s += c;
            }
            pre = c;
        }
        int len = s.size();
        vector<vector<vector<int>>> memo(len, vector<vector<int>>(m, vector<int>(n, 0)));
        function<int(int, int, int)> dfs = [&](int i, int r, int c) -> int {
            if (i == len) return 0;
            int res = 0x3f3f3f3f;
            if (memo[i][r][c] > 0) { return memo[i][r][c]; }
            int idx = s[i] - 'a';
            for (auto nxt : arr[idx]) {
                int diff = abs(r - nxt.first) + abs(c - nxt.second);
                res = min(res, dfs(i + 1, nxt.first, nxt.second) + diff);
            }
            memo[i][r][c] = res;
            return res;
        };

        return dfs(0, 0, 0) + rep + len;
    }
};

//int ans =
