// Problem: T511489 【入门赛】G 数字 Easy Version
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/T511489?contestId=197857
// Memory Limit: 512 MB
// Time Limit: 1000 ms

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
    int n,p;cin>>n>>p;
    string s = "";
    if(n*9<p) {
    	cout<<1;
    	rep(i,2,n){
    		cout<<0;
    	}
    	cout<<endl;return;
    }else{
    	if((n-1)*9>=p) p--;
    	else{
    		cout<<p-(n-1)*9;
	    	rep(i,2,n){
	    		cout<<9;
	    	}
	    	cout<<endl;return;
    	}
	    while(p){
	    	if(p>9){
	    		s.pb('9');
	    		p-=9;
	    	}else{
	    		s.pb(p+'0');
	    		p=0;
	    	}
	    }
	    if(s.length()<n){
	    	while(s.length()<n-1){
		    	s.pb('0');
		    }
		    s.pb('1');
	    }
	    if(s.length()>n){
	    	
	    }
	    reverse(all(s));
	    cout<<s<<endl;
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
