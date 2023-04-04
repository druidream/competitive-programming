/*
 sample:
 CF 1791F
 */
#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & (-S))

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

class FenwickTree {
private:
    vi ft;
public:
    FenwickTree(int m) { ft.assign(m+1, 0); }

    void build(const vll &f) {
        int m = (int)f.size()-1;
        ft.assign(m+1, 0);
//        for (int i = 1; i <= m)
    }
    int rsq(int j) {
        int sum = 0;
        for(; j; j -= LSOne(j)) {
            sum += ft[j];
        }
        return sum;
    }
    int req(int i, int j) { return rsq(j) - rsq(i-1); }
    void update(int i, int v) {
        for (; i < (int)ft.size(); i += LSOne(i)) {
            ft[i] += v;
        }
    }
};

class RUPQ {
private:
    FenwickTree ft;
public:
    RUPQ(int m) : ft(FenwickTree(m)) {}
    void range_update(int ui, int uj, int v) {
        ft.update(ui, v);
        ft.update(uj+1, -v);
    }
    ll point_query(int i) { return ft.rsq(i); }
};
