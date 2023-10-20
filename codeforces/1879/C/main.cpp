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
const int mod = 998244353;
int d4[5] = { 0, 1, 0, -1, 0 };

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;

ll get_pow(ll x, ll n){
    ll ans=1;
    while(n){
        if(n&1){
            ans=ans*x%mod;
        }
        x=x*x%mod;
        n>>=1;
    }
    return (ans+mod)%mod;
}

ll comb(ll m, ll n) {
    ll a = 1, b = 1;
    for(ll i=n,j=0; j<m; j++,i--){
        a=i*a%mod;
    }
    for(ll i=2; i<=m; i++){
        b=b*i%mod;
    }
    return a*get_pow(b, mod-2)%mod;
}

void solve() {
    string s; cin >> s;
    int n = s.size();
    vll f;
    int len = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            len++;
        } else {
            f.push_back(len);
            len = 1;
        }
    }
    f.push_back(len);
    // printInline(f)
    int x = n - f.size();
    ll y = 1;
    auto perm = [&](ll v) -> ll {
        ll ans = 1;
        for (ll i = 1; i <= v; i++) {
            ans = (ans * i) % mod;
        }
        return ans;
    };
    rep(i, f.size()) {
        y = (y * f[i]) % mod;
    }
    y = (y * perm(x)) % mod;
    // ll parts = 0;
    // rep(i, f.size()) {
    //     if (f[i] == 1) continue;
    //     y = (y * perm(f[i])) % mod;
    //     parts++;
    // }
    // y = (y * perm(parts)) % mod;
    // ll m = 0;
    // rep(i, f.size()) {
    //     if (f[i] == 1) continue;
    //     m += f[i];
    // }
    // // ll y = comb(x, m);
    // rep(i, f.size()) {
    //     if (f[i] == 1) continue;
    //     y = (y * perm(f[i])) % mod;
    // }
    cout << x << ' ' << y << '\n';
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
    while (T--)
        solve();
    return 0;
}
