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
typedef pair<int, int> pii;

class FenwickTree {                              // index 0 is not used
private:                                // internal FT is an array
public:
  vll ft;        
  FenwickTree(int m) { ft.assign(m+1, 0); }      // create an empty FT

  void build(const vll &f) {
    int m = (int)f.size()-1;                     // note f[0] is always 0
    ft.assign(m+1, 0);
    for (int i = 1; i <= m; ++i) {               // O(m)
      ft[i] += f[i];                             // add this value
      if (i+LSOne(i) <= m)                       // i has parent
        ft[i+LSOne(i)] += ft[i];                 // add to that parent
    }
  }

  FenwickTree(const vll &f) { build(f); }        // create FT based on f

  FenwickTree(int m, const vi &s) {              // create FT based on s
    vll f(m+1, 0);
    for (int i = 0; i < (int)s.size(); ++i)      // do the conversion first
      ++f[s[i]];                                 // in O(n)
    build(f);                                    // in O(m)
  }

  ll rsq(int j) {                                // returns RSQ(1, j)
    ll sum = 0;
    for (; j; j -= LSOne(j))
      sum += ft[j];
    return sum;
  }

  ll rsq(int i, int j) { return rsq(j) - rsq(i-1); } // inc/exclusion

  // updates value of the i-th element by v (v can be +ve/inc or -ve/dec)
  void update(int i, ll v) {
    for (; i < (int)ft.size(); i += LSOne(i))
      ft[i] += v;
  }

  int select(ll k) {                             // O(log m)
    int p = 1;
    while (p*2 < (int)ft.size()) p *= 2;
    int i = 0;
    while (p) {
      if (k > ft[i+p]) {
        k -= ft[i+p];
        i += p;
      }
      p /= 2;
    }
    return i+1;
  }
};

void solve() {
    int n, m, q; cin >> n >> m >> q;
    string s; cin >> s;
    vector<pii> lr(m);
    vector<int> qs(q);
    rep(i, m) {
        int l, r; cin >> l >> r;
        lr[i] = pii(l, r);
    }
    rep(j, q) {
        cin >> qs[j];
    }
    vi t;
    int mn = n + 1, mx = -1;
    rep(i, m) {
        int l = lr[i].first, r = lr[i].second;
        for (int x = min(mn, l); x <= max(mx, r); x++) {
            t.push_back(x);
        }
        mn = min(mn, l);
        mx = max(mx, r);
    }
    vll f(n + 1);
    ll sum = 0;
    rep(i, n) {
        sum += s[i] == '1';
        f[i + 1] += s[i] == '1';
    }
    FenwickTree ft(n);
    ft.build(f);
    // printInline(ft.ft)
    vi res;
    int k = sum;
    rep(j, q) {
        int i = qs[j] - 1;
        if (s[i] == '0') {
            s[i] = '1';
            k++;
            ft.update(i + 2, 1);
        } else {
            s[i] = '0';
            k--;
            ft.update(i + 2, -1);
        }
        res.push_back(k - ft.rsq(k));
        cout << "k: " << k << ' ' << s << endl;
        printInline(ft.ft)
    }
    rep(i, res.size()) {
        print(res[i])
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int T; cin >> T;
    // while (T--)
        solve();
    return 0;
}
