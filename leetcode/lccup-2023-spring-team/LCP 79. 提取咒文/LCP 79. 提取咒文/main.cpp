#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int extractMantra(vector<string>& matrix, string mantra) {
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        int m = matrix.size(), n = matrix[0].size();
        queue<int> q;
        q.push(0);
        unordered_set<int> vis;
        vis.insert(0);
        int step = 1;
        while (!q.empty()) {
            int cnt = q.size();
            while (cnt--) {
                int key = q.front();
                q.pop();
                int i = key >> 16;
                int j = (key >> 8) & 255;
                int k = key & 255;
//                cout << i << ' ' << j << ' ' << k << endl;
                if (matrix[i][j] == mantra[k]) {
                    if (k == mantra.size() - 1) return step;
                    int p = (i << 16) + (j << 8) + k + 1;
                    if (vis.find(p) == vis.end()) {
                        vis.insert(p);
                        q.push(p);
                    }
                }
                for (int t = 0; t < 4; t++) {
                    int x = i + dx[t], y = j + dy[t];
                    if (0 <= x && x < m && 0 <= y && y < n) {
                        int p = (x << 16) + (y << 8) + k;
                        if (vis.find(p) == vis.end()) {
                            vis.insert(p);
                            q.push(p);
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};

int main() {
    vector<string> mat = {"sd","ep"};
    int ans = Solution().extractMantra(mat, "speed");
    cout << ans << endl;
}
