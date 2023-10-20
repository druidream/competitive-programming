#include <bits/stdc++.h>
using namespace std;

// CE
typedef pair<int, vector<int>> pi;
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        priority_queue<pi, vector<pi>(), greater<pi>()> pq;
        int firstSum = 0;
        vector<int> firstIdx(m, 0);
        for (auto &row : mat) {
            firstSum += row[0];
        }
        pq.push({ firstSum, firstIdx });
        int ans = 0;
        while (k--) {
            auto item = pq.top();
            pq.pop();
            int u = item.first;
            ans = u;
            auto idx = item.second;
            for (int i = 0; i < m; i++) {
                if (idx[i] + 1 == n) continue;
                auto t = idx;
                u -= t[i];
                t[i]++;
                u += t[i];
                pq.push({ u, t });
            }
        }
        return ans;
    }
};

int main() {
    Solution *sol = new Solution();
    vector<vector<int>> mat = {{1,3,11},{2,4,6}};
    int ans = sol->kthSmallest(mat, 5);
    cout << ans << endl;
}
