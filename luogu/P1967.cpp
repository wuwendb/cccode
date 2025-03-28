// Problem: P1967 [NOIP2013 提高组] 货车运输
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1967
// Memory Limit: 128 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i) 
#define all(a) (a).begin(),(a).end() 
//#define ll long long  
#define int long long  
using namespace std;  
const int dx[4]{0,0,-1,1};
const int dy[4]{-1,1,0,0};
const int mx = 2e4+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  
int fath[mx];
int find(int x) {  
	return fath[x] == x ? x : fath[x] = find(fath[x]);  
}  
void dsu(){
	iota(begin(fath), end(fath), 0);
}
struct Edge{
	int to,w,next;
}edge[mx*5];
int head[mx],cnt,lg[mx];
void init(){
	rep(i,0,(mx<<1)-1){
		head[i] = -1;
		edge[i].next = -1;
	}
	cnt = 0;
}
void addedge(int u,int v,int w){
	edge[cnt].to = v;
	edge[cnt].next = head[u];
	edge[cnt].w = w;
	head[u] = cnt++;
}  
int fa[mx][20],val[mx][20],deep[mx];
void dfs(int x,int fath,int w){
	deep[x] = deep[fath]+1;
	fa[x][0] = fath;
	val[x][0] = w;
	for(int i = 1;(1<<i)<=deep[x];i++){
		fa[x][i] = fa[fa[x][i-1]][i-1];
		val[x][i] = min(val[x][i-1],val[fa[x][i-1]][i-1]);
	}
	for(int i = head[x];i!=-1;i = edge[i].next){
		if(edge[i].to!=fath){
			dfs(edge[i].to,x,edge[i].w);
		}
	}
}  
int LCA(int x,int y){
	if(find(x)!=find(y)) return -1;
	if(deep[x]<deep[y]) swap(x,y);
	int ans = LLONG_MAX;
	while(deep[x]>deep[y]){
		ans = min(ans,val[x][lg[deep[x]-deep[y]]-1]);
		x = fa[x][lg[deep[x]-deep[y]]-1];
	}
	if(x==y) return ans;
	for(int i = lg[deep[x]]-1;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			ans = min({ans,val[x][i],val[y][i]});
			x = fa[x][i];y = fa[y][i];
		}
	}
	ans = min({ans,val[x][0],val[y][0]});
	return ans;
}
void solve() {  
    int n,m;cin>>n>>m;
    init(); 
    for (int i = 1; i <= n; i++) {
		lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
	}
	vector<array<int,3>> g(m+1);
    rep(i,1,m){
    	int u,v,w;cin>>u>>v>>w;
    	g[i][0] = u;
    	g[i][1] = v;
    	g[i][2] = w;
    }
    
    auto kruskal = [&](){
    	sort(g.begin()+1,g.begin()+1+m,[](const auto& a1,const auto& a2){
    		return a1[2]>a2[2];
    	});
    	dsu();
    	rep(i,1,m){
    		auto [u,v,w] = g[i];
    		if(find(u)!=find(v)){
    			fath[find(u)] = find(v);
    			addedge(u,v,w);
    			addedge(v,u,w);
    		}
    	}
    };
    kruskal();
    rep(i,1,n){
    	if(!deep[i]){
    		dfs(i,0,0);
    	}
    }
    int q;cin>>q;
    rep(i,1,q){
    	int x,y;cin>>x>>y;
    	cout<<LCA(x,y)<<endl;
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
