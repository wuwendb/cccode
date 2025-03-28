// Problem: T497975 两座城市的 543 千米
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/T497975?contestId=188303
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i) 
#define all(a) begin(a),end(a) 
//#define ll long long  
#define int long long  
using namespace std;  
const int dx[4]{0,0,-1,1};
const int dy[4]{-1,1,0,0};
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  

  
void solve() {  
    int n,m,a,b;cin>>n>>m>>a>>b;
    int ans = 0;
    rep(i,1,m){
    	int l;cin>>l;
    	int level = 0;
    	rep(j,1,l){
    		int x;cin>>x;
    		if(x==a&&level==0){
    			level=1;
    		}else if(x==b&&level==1){
    			level=2;
    		}
    	}
    	if(level==2){
    		ans++;
    	}
    }
    cout<<ans<<endl;
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
