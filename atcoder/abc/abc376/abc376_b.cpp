// Problem: B - Hands on Ring (Easy)
// Contest: AtCoder - AtCoder Beginner Contest 376
// URL: https://atcoder.jp/contests/abc376/tasks/abc376_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i) 
#define all(a) begin(a),end(a)
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
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
    int n,q;cin>>n>>q;
    int l=1,r=2;
    int ans = 0;
    rep(i,1,q){
    	char h;int t;cin>>h>>t;
    	if(h=='L'){
    		if(t==l) continue;
    		if(l<r){
    			if(t>l&&t<r) ans+=t-l;
    			else ans+=(l+n-t)%n;	
    		}else{
    			if(t>r&&t<l) ans+=l-t;
				else ans+=(t+n-l)%n;	
    		}
			l=t;
    	}else{
    		if(t==r) continue;
    		if(l<r){
    			if(t>l&&t<r){
    				ans+=r-t;
    			}else{
    				ans+=(t+n-r)%n;
    			}
    		}else{
    			if(t<l&&t>r){
    				ans+=t-r;
    			}else{
    				ans+=(r+n-t)%n;
    			}
    		}
			r=t;
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
