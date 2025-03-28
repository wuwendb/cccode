// Problem: 小红的序列乘积
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/87656/B
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
	int n;cin>>n;
	vector<int> f(n);
	f[0]=1;int ans=0;
	rep(i,1,n){
		int x;cin>>x;
		x%=10;
		f[i] = f[i-1]*x;f[i]%=10;ans+=(f[i]==6);
	}
	cout<<ans<<endl;

    
}  
  
signed main() {  
    ios_base::sync_with_stdio(false);  
    cin.tie(nullptr);  
    int t=1;  
//    cin >> t; 
    cout<<fixed<<setprecision(1); 
    while (t--) {  
        solve();  
    }  
//    cout<<pow(2,22)<<endl;  
    return 0;  
}
