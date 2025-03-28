// Problem: P3379 【模板】最近公共祖先（LCA）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3379
// Memory Limit: 512 MB
// Time Limit: 2000 ms

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
const int mx = 5e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  
struct Edge{
	int to,w,next;
}edge[mx<<1];
int head[mx<<1],cnt;
void init(){
	rep(i,0,2*mx-1){
		edge[i].next = -1;
		head[i] = -1;
	}
	cnt = 0;
}
void addedge(int u,int v){
	edge[cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}  
int deep[mx],siz[mx],son[mx],top[mx],fa[mx];
void dfs1(int x,int fath){
	deep[x] = deep[fath]+1;
	fa[x] = fath;
	siz[x] = 1;
	for(int i = head[x];i!=-1;i=edge[i].next){
		int y = edge[i].to;
		if(y!=fath){
			fa[y]=x;
			dfs1(y,x);
			siz[x]+=siz[y];
			if(!son[x]||siz[son[x]]<siz[y]){
				son[x] = y;
			}
		}
	}
}
void dfs2(int x,int topx){
	top[x] = topx;
	if(!son[x]) return;//叶子
	dfs2(son[x],topx);
	for(int i = head[x];~i;i=edge[i].next){
		int y = edge[i].to;
		if(y!=fa[x]&&y!=son[x]){
			dfs2(y,y);
		}
	}
}
int LCA(int x,int y){
	while(top[x]!=top[y]){
		if(deep[top[x]]<deep[top[y]]) swap(x,y);
		x = fa[top[x]]; 
	}
	return deep[x]<deep[y]?x:y;
}
void solve() {  
    init();
    int n,m,root;cin>>n>>m>>root;
    rep(i,1,n-1){
    	int u,v;cin>>u>>v;
    	addedge(u,v);addedge(v,u);
    }
    dfs1(root,0);
    dfs2(root,root);
    rep(i,1,m){
    	int u,v;cin>>u>>v;
		cout<<LCA(u,v)<<endl;
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
