// Problem: T500877 【MX-J3-T1】Seats
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/T500877?contestId=193566
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
    int a,b;cin>>a>>b;
    string s;cin>>s;
    if(s.length()<a+b){
		cout<<-1<<endl;
		return; 
	}
    int ss=0,tt=0;
    for(auto c:s) {
    	if(c=='S') ss++;
    	else tt++;
    }
    if(ss>=a&&tt>=b){
    	cout<<0<<endl;
    	return;
    }
    if(ss<a){
		cout<<a-ss<<endl;
    }else{
		cout<<b-tt<<endl;
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
