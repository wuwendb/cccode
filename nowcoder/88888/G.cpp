// Problem: 小红的双排列构造
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/88888/G
// Memory Limit: 524288 MB
// Time Limit: 2000 ms

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
    int n,k;cin>>n>>k;
    if(k==0){
    	if(n<=2){
    		cout<<-1<<endl;
    		return;
    	}
    	rep(i,1,n){
    		cout<<i<<" "<<i<<" ";
    	}
    	cout<<endl;
    }else if(k==1){
    	if(n==1){
    		cout<<-1<<endl;
    		return;
    	}
    	cout<<1<<" ";
    	rep(i,1,n){
    		cout<<i<<" ";
    	}
    	rep(i,2,n){
    		cout<<i<<" ";
    	}
    	cout<<endl;
    }else{
    	int len = n+1-k+1;
    	rev(i,len,1){
    		cout<<i<<" ";
    	}
    	rep(i,len+1,n){
    		cout<<i<<" ";
    	}
    	rep(i,1,n){
    		cout<<i<<" ";
    	}
    	cout<<endl;
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
