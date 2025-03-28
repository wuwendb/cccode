// Problem: P10859 [HBCPC2024] Nana Likes Polygons
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P10859
// Memory Limit: 512 MB
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
    int n;cin>>n;
    vector<array<int,2>> node(n);
    rep(i,1,n){
	   	cin>>node[i-1][0]>>node[i-1][1];
    }
    double ans = 1e6+10;
    rep(i,0,n-3){
    	rep(j,i+1,n-2){
    		rep(k,j+1,n-1){
    			int x1 = node[i][0],y1 = node[i][1];
    			int x2 = node[j][0],y2 = node[j][1];
    			int x3 = node[k][0],y3 = node[k][1];
    			double sum =0.5*abs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
    			if(sum==0){
    				continue;
    			}
    			ans = min(ans,sum);
    		}
    	}
    }
    if(ans==1e6+10){
    	cout<<-1<<endl;
    }else{
    	cout<<ans<<endl;
    }
}  
  
signed main() {  
    ios_base::sync_with_stdio(false);  
    cin.tie(nullptr);  
    int t=1;  
   cin >> t; 
    cout<<fixed<<setprecision(6); 
    while (t--) {  
        solve();  
    }  
//    cout<<pow(2,22)<<endl;  
    return 0;  
}
