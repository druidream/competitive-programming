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

#define debugMap(mp) cout << "map: \n"; for (auto &kv : mp) cout << kv.first << ' ' << kv.second << '\n'; cout << "-----" << endl;
#define debugStack(st) cout << "stack: "; while (st.size()) { cout << st.top() << ' '; st.pop(); } cout << '\n';

double EPS = 1e-9;
int INF = 0x3f3f3f3f;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};
// const int mod = 998244353;
int d4[5] = { 0, 1, 0, -1, 0 };

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;

void solve() {
    string s; cin >> s;
    ll pos; cin >> pos;
    ll n = s.size();
    // number prefix chars in S < pos
    // len: length of cur si
    ll pre = 0, cur = n;
    while (cur >= 0 && pre + cur < pos) {
        pre += cur;
        cur -= 1;
    }
    // final len: cur
    ll remove = n - cur;
    pos -= pre;

    priority_queue<pair<char, int>> pq;
    rep(i, n) {
        pq.emplace(s[i], -i);
    }
    while (remove--) {
        pq.pop();
    }
    vector<pair<int, char>> arr;
    while (!pq.empty()) {
        auto [c, i] = pq.top(); pq.pop();
        arr.push_back({ -i, c });
    }
    sort(arr.begin(), arr.end());
    string res = "";
    for (auto &[i, c]: arr) {
        res += c;
    }
    cout << res << ' ' << pos << endl;
    // cout << res[pos - 1];
}

void solve1() {
    string s; cin >> s;
    ll pos; cin >> pos;
    ll n = s.size();
    ll pre = 0, cur = n;
    while (cur >= 0 && pre + cur < pos) {
        pre += cur;
        cur -= 1;
    }
    ll remove = n - cur;
    pos -= pre;

    vector<int> removedIndex;
    stack<char> stk;
    for (int i = 0; i < n; i++) {
        if (remove == 0) {
            break;
        }
        while (!stk.empty() && s[i] < s[stk.top()] && remove) {
            removedIndex.push_back(stk.top());
            stk.pop();
            remove--;
        }
        stk.push(i);
    }
    // printInline(removedIndex)
    sort(removedIndex.begin(), removedIndex.end());
    string res;
    int j = 0;
    rep(i, n) {
        if (j == removedIndex.size()) {
            res += s[i];
            continue;
        }
        if (i == removedIndex[j]) {
            j++;
        } else {
            res += s[i];
        }
    }
    while (remove--) {
        res.pop_back();
    }
    // cout << res << ' ' << pos << endl;
    cout << res[pos - 1];
}
// fxictuogfaecjxeseuvdydfdkbqaophckkukyeucpfnep
// fxictuogfaecjxeseuvdydfdkbqaophckkukyescpfnen
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve1();
    cout << '\n';
    return 0;
}
