// Problem: 求值
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/87865/G
// Memory Limit: 524288 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i)  
//#define ll long long  
#define int long long  
using namespace std;  
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  

  
void solve() {  
    int a,b,c,n,w;cin>>a>>b>>c>>n>>w;
    if(b<c) swap(b,c);
    int ans = LLONG_MAX;
    rep(i,0,n){
    	int l=-1,r=n-i+1;
    	while(l+1<r){
    		int mid = l+r>>1;
    		((i*a+mid*b+(n-mid-i)*c > w)?r:l)=mid;
    	}
		if(l!=-1) ans = min(abs(i*a+l*b+(n-l-i)*c-w),ans);
    	if(r!=n-i+1) ans = min(abs(i*a+r*b+(n-r-i)*c-w),ans);
    }
    cout<<ans<<endl;
}  
  
signed main() {  
    ios_base::sync_with_stdio(false);  
    cin.tie(nullptr);  
    int t=1;  
    cin >> t; 
    cout<<fixed<<setprecision(1); 
    while (t--) {  
        solve();  
    }  
    // cout<<pow(2,22)<<endl;  
    return 0;  
}
