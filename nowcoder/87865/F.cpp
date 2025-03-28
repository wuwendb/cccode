// Problem: 累加器
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/87865/F
// Memory Limit: 524288 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i)  
//#define ll long long  
#define int long long  
using namespace std;  
const int mx = 2e6+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  

  
void solve() {  
	vector<int> g(mx);
	for(int i =1;i<mx;i++){
		g[i] = g[i-1]+ __builtin_popcount(i^(i-1));
	}
	int t;cin>>t;
	int x,y;
	while(t--){
		cin>>x>>y;
		cout<<g[x+y]-g[x]<<endl;
	}
    
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
