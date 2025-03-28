// Problem: keillempkill学姐の卷积
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/87865/J
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
    int n,m;cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(n));
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		cin>>a[i][j];
    	}
    }
    vector<vector<int>> b(m,vector<int>(m));
    for(int i=0;i<m;i++){
    	for(int j=0;j<m;j++){
    		cin>>b[i][j];
    	}
    }
    for(int i = 0;i<m-n+1;i++){
    	for(int j=0;j<m-n+1;j++){
    		int ans =0;
    		for(int x=0;x<n;x++){
    			for(int y=0;y<n;y++){
    				ans+=a[x][y]*b[x+i][y+j];
    			}
    		}
    		cout<<ans<<" \n"[j==m-n];
    	}
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
