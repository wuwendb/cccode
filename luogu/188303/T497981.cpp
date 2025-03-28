// Problem: T497981 保持连接的方式
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/T497981?contestId=188303
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
    int n,m,k,t;cin>>n>>m>>k>>t;
    vector<vector<vector<int>>> g(n+1,vector<vector<int>>(m+1));
    rep(i,1,t){
    	int a,x,y;
    	cin>>a>>x>>y;
    	if(g[x][y].size()<k){
    	  g[x][y].push_back(a);
    	  cout<<-1<<endl;
    	}	
    	else{
    		int index = 0;
		    for (int i = 0; i < g[x][y].size(); ++i) {
		        if (g[x][y][i] <= g[x][y][index]) {
		            index = i;
		        }
		    }
		    cout<<g[x][y][index]<<" "<<k-1-index<<endl;
		    g[x][y].erase(g[x][y].begin() + index);
			g[x][y].push_back(a);	
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
