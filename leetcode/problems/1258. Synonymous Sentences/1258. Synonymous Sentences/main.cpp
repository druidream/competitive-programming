#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

class UnionFind {                                // OOP style
private:
  vi p, rank, setSize;                           // vi p is the key part
  int numSets;
public:
  UnionFind(int N) {
    p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
    rank.assign(N, 0);                           // optional speedup
    setSize.assign(N, 1);                        // optional feature
    numSets = N;                                 // optional feature
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  int numDisjointSets() { return numSets; }      // optional
  int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional

  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;                 // i and j are in same set
    int x = findSet(i), y = findSet(j);          // find both rep items
    if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
    p[x] = y;                                    // set x under y
    if (rank[x] == rank[y]) ++rank[y];           // optional speedup
    setSize[y] += setSize[x];                    // combine set sizes at y
    --numSets;                                   // a union reduces numSets
  }
};

class Solution {
public:
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        vector<string> arr;
        map<string, int> mp;
        int cnt = 0;
        for (int i = 0; i < synonyms.size(); i++) {
            string s = synonyms[i][0], t = synonyms[i][1];
            if (mp.find(s) == mp.end()) {
                mp[s] = cnt++;
                arr.push_back(s);
            }
            if (mp.find(t) == mp.end()) {
                mp[t] = cnt++;
                arr.push_back(t);
            }
        }
        UnionFind uf(cnt);
        for (int i = 0; i < synonyms.size(); i++) {
            string s = synonyms[i][0], t = synonyms[i][1];
            int u = mp[s], v = mp[t];
            uf.unionSet(u, v);
        }
        string w = "";
        vector<string> words;
        for (auto &c : text) {
            if (c != ' ') w += c;
            if (c == ' ') {
                words.push_back(w);
                w = "";
            }
        }
        words.push_back(w);
        vector<string> res(1, "");
        for (auto &w : words) {
            if (mp.find(w) != mp.end()) {
                int root = uf.findSet(mp[w]);
                vector<string> tmp;
                for (int i = 0; i < cnt; i++) {
                    if (uf.findSet(i) == root) {
                        for (int j = 0; j < res.size(); j++) {
                            tmp.push_back(res[j] + ' ' + arr[i]);
                        }
                    }
                }
                res = tmp;
            } else {
                for (auto &s : res) {
                    s += w;
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution s = Solution();
    vector<vector<string>> a = {{"happy","joy"},{"cheerful","glad"}};
    s.generateSentences(a, "I am happy today but was sad yesterday");
}

