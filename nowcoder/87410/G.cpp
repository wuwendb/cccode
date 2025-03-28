// Problem: 牛郎织女来相会
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/87410/G
// Memory Limit: 524288 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i) 
#define all(a) (a).begin(),(a).end() 
#define ll long long  
// #define int long long  
using namespace std;  
const int dx[4]{0,0,-1,1};
const int dy[4]{-1,1,0,0};
const int mx = 2e6+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  
ll inv[mx], fac[mx];  //分别表示逆元和阶乘  
//快速幂  
ll quickPow(ll a,ll b){  
    ll ans=1;  
    while(b){  
        if(b&1)  
            ans=(ans*a)%mod;  
        b>>=1;  
        a=(a*a)%mod;  
    }  
    return ans;  
}  
  
void init(){  
    //求阶乘  
    fac[0]=1;  
    for(int i=1;i<mx;i++){  
        fac[i]=fac[i-1]*i%mod;  
    }  
    //求逆元  
    inv[mx-1]=quickPow(fac[mx-1],mod-2);  
    for(int i=mx-2;i>=0;i--){  
        inv[i]=inv[i+1]*(i+1)%mod;  
    }  
}  
ll C(int n,int m){  
    if(m>n){  
        return 0;  
    }  
    if(m==0)  
        return 1;  
    return fac[n]*inv[m]%mod*inv[n-m]%mod;  
}
  
void solve() {  
	init();
    ll n,m;cin>>n>>m;
    cout<<(C(m,n-1)*(n-2)%mod*quickPow(2,n-3))%mod<<endl;
}  
  
signed main() {  
    ios_base::sync_with_stdio(false);  
    cin.tie(nullptr);  
    int t=1;  
    // cin >> t; 
    cout<<fixed<<setprecision(1); 
    while (t--) {  
        solve();  
    }  
    // cout<<pow(2,22)<<endl;  
    return 0;  
}
