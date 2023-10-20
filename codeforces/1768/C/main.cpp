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
const int mod = 998244353;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;

void solve() {
    int n; cin >> n;
    vi a(n); rep(i, n) cin >> a[i];
    vi p(n, -1), q(n, -1); // val, index
    priority_queue<pii> pq;
    rep(i, n) {
        pq.emplace(a[i], i);
    }
    if (pq.top().first != n) {
        print("NO")
        return;
    }
    while (!pq.empty()) {
        auto [x, i] = pq.top(); pq.pop();
        x--;
        if (p[x] == -1) {
            p[x] = i;
        } else if (q[x] == -1) {
            q[x] = i;
        } else {
            print("NO")
            return;
        }
    }

    // printInline(p)
    // printInline(q)
    int j = n - 1;
    bool ans = true;
    for (int i = n - 1; i >= 0; i--) {
        if (p[i] != -1) continue;
        while (q[j] == -1) j--;
        if (i > j) {
            ans = false;
            break;
        }
        p[i] = q[j];
        j--;
    }
    // printInline(p)
    // printInline(q)
    j = n - 1;
    set<int> seen;
    for (int i = n - 1; i >= 0; i--) {
        if (q[i] != -1) {
            seen.insert(q[i]);
            continue;
        }
        while (p[j] == -1 || seen.count(p[j])) {
            j--;
        }
        if (i > j) {
            ans = false;
            break;
        }
        seen.insert(p[j]);
        q[i] = p[j];
        j--;
    }
    printBool(ans)
    if (ans) {
        vi a(n), b(n);

    // printInline(p)
    // printInline(q)
        rep(i, n) {
            a[p[i]] = i + 1;
            b[q[i]] = i + 1;
        }
        printInline(a)
        printInline(b)
    }
}

terminate_handler old_terminate_handler = nullptr;

void new_terminate_handler() {
    std::cout << "terminate due to error" << std::endl;

    // print_stacktrace();
    if( old_terminate_handler != nullptr ) {
        old_terminate_handler();
    } else {
        std::abort();
    }
}
void sig_handler(int signal) {
    new_terminate_handler();
}

// ...
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    old_terminate_handler = get_terminate();
    set_terminate(new_terminate_handler);

std::signal(SIGTERM, sig_handler);
std::signal(SIGSEGV, sig_handler);
std::signal(SIGINT, sig_handler);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        // cout << T << endl;
        solve();
    return 0;
}
