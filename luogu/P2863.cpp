// Problem: P2863 [USACO06JAN] The Cow Prom S
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2863
// Memory Limit: 128 MB
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
vector<int> g[mx],g2[mx];
int w[mx];
int n,m;
int outde[mx],dis[mx],ans;

int dfn[mx],low[mx],dfncnt,stac[mx],vis[mx],top;
int scc[mx],sc;
int sz[mx];
  
void tarjan(int u){
	low[u] = dfn[u] = ++dfncnt,stac[++top] = u,vis[u] = 1;
	for(auto v:g[u]){
		if(!dfn[v]){
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}else if(vis[v]){
			low[u] = min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u]){
		++sc;
		while(stac[top]!=u){
			scc[stac[top]]=sc;
			sz[sc]++;
			vis[stac[top]] = 0;
			--top;
		}
		scc[stac[top]] = sc;
		sz[sc] ++;
		vis[stac[top]] = 0;
		--top;
		if(sz[sc]>1){
			ans++;
		}
	}
}  

void solve() { 
    cin>>n>>m;
    rep(i,1,m){
    	int u,v;cin>>u>>v;
    	g[u].push_back(v);
    }
    rep(i,1,n){
    	if(!dfn[i]){
    		tarjan(i);
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
