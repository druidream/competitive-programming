#include <bits/stdc++.h>

using ll = long long;
const int mod = 998244353;
const int maxn = 1 << 21;
int k,p[maxn],vis[maxn],x,ans=1;

int main() {
    scanf("%d",&k);
    memset(p,-1,sizeof(p));
    for (int i = 0; i < (1 << k); ++ i) {
        scanf("%d",&x);
        if (x != -1) p[x - 1] = i;
    }
    for (int i = 1; i <= k; ++ i) {
        int lim = (1 << i);
        int cnt = 0, coef = 1;
        memset(vis,0,sizeof(vis));
        for (int j = 0; j < lim; ++ j) {
            if (p[j] == -1) {
                if (j < (lim>>1)) ;
                else cnt ++;
                continue;
            }
            int key = p[j] >> (k - i);
            if (vis[key]) { puts("0"); return 0; }
            vis[key] = 1;
        }
        for (int j = 0; j < lim;  j += 2) if ((!vis[j]) && (!vis[j^1])) coef = coef * 2 %mod;
        //printf(">%d %d\n",i,cnt);
        ans = (ll) ans * coef % mod;
        for (int j = 1; j <= cnt; ++ j) ans = (ll) ans * j % mod;
    } printf("%d",ans);
    return 0;
}
