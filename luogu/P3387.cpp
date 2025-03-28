// Problem: P3387 【模板】缩点
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3387
// Memory Limit: 125 MB
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
int inde[mx],dis[mx],ans;

int dfn[mx],low[mx],dfncnt,stac[mx],vis[mx],top;
int scc[mx],sc;
int sv[mx];
  
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
			sv[sc]+=w[stac[top]];
			vis[stac[top]] = 0;
			--top;
		}
		scc[stac[top]] = sc;
		sv[sc] += w[u];
		vis[stac[top]] = 0;
		--top;
	}
}  
void topo(){
	queue<int> q;
	rep(i,1,sc){
		if(!inde[i]){
			q.push(i);
			dis[i] = sv[i]; 
		}
	}
	while(!q.empty()){
		int ff = q.front();
		q.pop();
		for(auto v:g2[ff]){
			dis[v] = max(dis[v],dis[ff]+sv[v]);
			inde[v]--;
			if(!inde[v]) q.push(v);
		}
	}
	rep(i,1,sc){
		ans = max(ans,dis[i]);
	}
	cout<<ans<<endl;
	
}
void solve() { 
    cin>>n>>m;
    rep(i,1,n){
    	cin>>w[i];
    }
    rep(i,1,m){
    	int u,v;cin>>u>>v;
    	g[u].push_back(v);
    }
    rep(i,1,n){
    	if(!dfn[i]){
    		tarjan(i);
    	}
    }
    rep(u,1,n){
    	for(auto v:g[u]){
    		if(scc[u]!=scc[v]){
    			g2[scc[u]].push_back(scc[v]);
    			inde[scc[v]]++;
    		}
    	}
    }
    topo();
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
