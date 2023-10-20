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

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M; cin >> N >> M;
    UnionFind uf(N + 1);
    rep(i, M) {
        int u, v; cin >> u >> v;
        uf.unionSet(u, v);
    }
    int K; cin >> K;
    vector<pair<int, int>> xy;
    unordered_set<ll> seen;
    rep(i, K) {
        int x, y; cin >> x >> y;
        xy.push_back({ x, y });
        int rootx = uf.findSet(x), rooty = uf.findSet(y);
        ll key = rootx * N + rooty;
        seen.insert(key);
    }
    int Q; cin >> Q;
    vector<pair<int, int>> pq;
    rep(i, Q) {
        int p, q; cin >> p >> q;
        pq.push_back({ p, q });
        int rootx = uf.findSet(p), rooty = uf.findSet(q);
        ll key1 = rootx * N + rooty, key2 = rooty * N + rootx;
        bool ans = true;
        if (seen.find(key1) != seen.end() || seen.find(key2) != seen.end()) {
            ans = false;
        }
        printBool(ans)
    }

    return 0;
}
