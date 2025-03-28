// Problem: E - Tree Game
// Contest: AtCoder - UNIQUE VISION Programming Contest 2025 Spring (AtCoder Beginner Contest 398)
// URL: https://atcoder.jp/contests/abc398/tasks/abc398_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= int(b); ++i)  
#define rev(i, a, b) for (int i = int(a); i >= (b); --i) 
#define all(a) begin(a),end(a)
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using namespace std;  

const int dx[4]{0,0,-1,1};
const int dy[4]{-1,1,0,0};
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  

  
void solve() {  
    int n;cin>>n;
    vector<vector<int>> adj(n);
    vector<vector<int>> vis(n,vector<int>(n,0));
    rep(i,0,n-2){
    	int u,v;cin>>u>>v;
    	u--,v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    	vis[u][v] = 1,vis[v][u]=1;
    }
    vector<int> color(n);
    auto dfs = [&](auto&& self,int i,int fa=-1)->void{
    	for(auto j:adj[i]){
    		if(j!=fa){
    			color[j] = color[i]^1;  
    			self(self,j,i);
    		}
    	}
    };
    dfs(dfs,0,-1);
    int tmp = accumulate(color.begin(),color.end(),0);
    int sum = tmp*(n-tmp)-n+1;
    if(sum&1){
    	cout<<"First"<<endl;
    }else {
    	cout<<"Second"<<endl;
    	int u,v;cin>>u>>v;
    	if(u==-1){
    		return;
    	}
    	u--,v--;
    	vis[u][v]=1,vis[v][u]=1;
    }
    for(int i=0;i<n;i++){
    	for(int j=i+1;j<n;j++){
    		if(vis[i][j]==0&&color[i]!=color[j]){
    			cout<<i+1<<" "<<j+1<<endl;
    			int u,v;cin>>u>>v;
    			if(u==-1){
    				return;
    			}
    			u--,v--;
    			vis[u][v]=1,vis[v][u]=1;
    		}
    	}
    }
}  
  
signed main() {  
    // ios_base::sync_with_stdio(false);  
    // cin.tie(nullptr);  
    int t=1;  
    // cin >> t; 
    cout<<fixed<<setprecision(1); 
    while (t--) {  
        solve();  
    } 
    return 0;  
}
