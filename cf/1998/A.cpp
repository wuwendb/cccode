// Problem: A. Find K Distinct Points with Fixed Center
// Contest: Codeforces - Codeforces Round 965 (Div. 2)
// URL: https://codeforces.com/contest/1998/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms

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
	int xc,yc,k;cin>>xc>>yc>>k;
	int tx = xc*k,ty=yc*k;
	if(tx==0&&ty==0){
		if(k&1){
			cout<<0<<" "<<0<<endl;k--;
		}
		rep(i,1,k/2){
			cout<<i+100000<<" "<<i+100000<<endl;
			cout<< (-1)*(i+100000)<<" "<<(-1)*(i+100000)<<endl;
		}
	}else{
		cout<<tx<<" "<<ty<<endl;k--;
		if(k&1){
			cout<<0<<" "<<0<<endl;k--;
		}
		rep(i,1,k/2){
			cout<<i+100000<<" "<<i+100000<<endl;
			cout<< (-1)*(i+100000)<<" "<<(-1)*(i+100000)<<endl;
		}
	}
	
	
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
