//
//  math.cpp
//  cpp
//
//  Created by Jun Gu on 2023/2/17.
//
//  Sample problems:
//  CF1795D

#include <bits/stdc++.h>
typedef long long ll;

const ll mod=998244353;

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
