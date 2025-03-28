// Problem: P3388 【模板】割点（割顶）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3388
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
vector<int> g[mx];
int low[mx],dfn[mx],dfncnt,iscut[mx];
vector<int> ans;
int root;
void dfs(int u){
	low[u]=dfn[u]= ++dfncnt;
	int child = 0;
	for(auto v:g[u]){
		if(!dfn[v]){
			child++;
			dfs(v);
			low[u] = min(low[u],low[v]);
			if(low[v]>=dfn[u]&&u!=root){
				iscut[u]=1;
			}
		}else if(dfn[v]<dfn[u]){
			low[u] = min(low[u],dfn[v]);
		}
	}
	if(child>=2 && u==root) {
		iscut[u]=1;
	}
	
}  
void solve() {  
    int n,m;cin>>n>>m;
    rep(i,1,m){
    	int x,y;
    	cin>>x>>y;
    	g[x].push_back(y);
    	g[y].push_back(x);
    }
    rep(i,1,n){
    	if(!dfn[i]){
    		root = i;
    		dfs(i);
    	}
    }
    int ans = 0;
    rep(i,1,n){
    	if(iscut[i]) ans++;
    }
    cout<<ans<<endl;
    rep(i,1,n){
    	if(iscut[i]) cout<<i<<" ";
    }
    cout<<endl;
    
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
