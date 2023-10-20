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

void debugSet(multiset<int> st) {
    cout << "debug set: ";
    for (auto it: st) {
        cout <<   it << ' ';
    }
    cout << endl;
}

vector<int> solve() {
    int n; cin >> n;
    vi nums(n); rep(i, n) cin >> nums[i];
    int indexDifference, valueDifference; cin >> indexDifference >> valueDifference;

    if (indexDifference >= n) return { -1, -1 };
    multiset<int> st;
    for (int i = indexDifference; i < n; i++) {
        st.insert(nums[i]);
    }
    // debugSet(st);
    vector<int> ans = { -1, -1 };
    for (int i = 0; i < n; i++) {
        // print(i)
        int left = i - indexDifference;
        if (left >= 0) {
            st.insert(nums[left]);
        }
        auto mn = *st.begin(), mx = *st.rbegin();
        if (abs(mn - nums[i]) >= valueDifference) {
            for (int j = 0; j < n; j++) {
                if (abs(j - i) < indexDifference) continue;
                if (abs(nums[j] - nums[i]) >= valueDifference) {
                    return { i, j };
                    break;
                }
            }
            break;
        }
        if (abs(mx - nums[i]) >= valueDifference) {
            for (int j = 0; j < n; j++) {
                if (abs(j - i) < indexDifference) continue;
                if (abs(nums[j] - nums[i]) >= valueDifference) {
                    return { i, j };
                    break;
                }
            }
            break;
        }
        int right = i + indexDifference;
        // cout << "debug: " << i << ' ' << right << ' ' << nums[right] << endl;
        if (right < n) {
             if (st.find(nums[right]) != st.end()) {
                // cout << "set size: " << st.size() << endl;
                st.erase(st.begin(), st.find(nums[right]));
            };
        }
    }
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        auto a = solve();
        cout << "ans: " << a[0] << ' ' << a[1] << endl;
    }

    return 0;
}
