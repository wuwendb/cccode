// Problem: 构造mex
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/89860/D
// Memory Limit: 524288 MB
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
	int s,n,k;cin>>s>>n>>k;
	if(k==0){
		if(s>=n){
			 cout<<"YES"<<endl;
			 rep(i,1,n-1){
			 	cout<<1<<" ";
			 }
			 cout<<s-n+1<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}else{
		if(n<k-1){
			cout<<"NO"<<endl;
			return;
		} 
		int sum = 0;
		rep(i,0,k-1){
			sum+=i;
		}	
		if(sum>s||){
			cout<<"NO"<<endl;
		}else{
			if(s-sum!=k){
				cout<<"YES"<<endl;
				rep(i,0,k-1){
					cout<<i<<" ";
				}
				rep(i,1,n-k-1){
					cout<<0<<" ";
				}
				cout<<s-sum<<endl;
			}else{
				if(n-k<=1||k==1){
					cout<<"NO"<<endl;
				}else{
					cout<<"YES"<<endl;
					rep(i,0,k-1){
						cout<<i<<" ";
					}
					rep(i,1,n-k-2){
						cout<<0<<" ";
					}
					cout<<k-1<<" "<<1<<endl;
				}
			}
			
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
