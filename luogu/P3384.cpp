// Problem: P3384 【模板】重链剖分/树链剖分
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3384
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
#define ls (node << 1)  
#define rs (node << 1 | 1)  
int a[mx],new_a[mx],tree[mx*4],lazy[mx*4];  
  
void pushUp(int node){  
    tree[node]=tree[ls]+tree[rs];  
}  
  
void build(int node,int start,int end){  
    if(start==end){  
        tree[node]=new_a[start];  
        return;  
    }  
    int mid=start+end>>1;  
    build(ls,start,mid);  
    build(rs,mid+1,end);  
    pushUp(node);  
}  
  
void pushDown(int node,int start,int end){  
    int mid = start+end>>1;  
    lazy[ls] += lazy[node];  
    lazy[rs] += lazy[node];  
    tree[ls] += lazy[node]*(mid-start+1);  
    tree[rs] += lazy[node]*(end-mid);  
    lazy[node] = 0;  
}  
  
void add(int node,int start,int end,int l,int r,int val){  
    if(l<=start&&end<=r){  
        tree[node]+=(end-start+1)*val;  
        lazy[node]+=val;  
        return;  
    }  
    if(lazy[node]!=0){  
        pushDown(node,start,end);  
    }  
    int mid=start+end>>1;  
    if(l<=mid) add(ls,start,mid,l,r,val);  
    if(r>mid) add(rs,mid+1,end,l,r,val);  
    pushUp(node);  
}  
  
int query(int node,int start,int end,int l,int r){  
    if(l<=start&&end<=r) return tree[node];  
    if(lazy[node]!=0){  
        pushDown(node,start,end);  
    }  
    int mid=start+end>>1;  
    int res=0;  
    if(l<=mid) res+=query(ls,start,mid,l,r);  
    if(r>mid) res+=query(rs,mid+1,end,l,r);  
    return res;  
}
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
int deep[mx],siz[mx],id[mx],son[mx],top[mx],fa[mx],num=0;
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
	id[x] = ++num;
	new_a[num] = a[x];
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
int n,m,r,p;
void update_range(int x,int y,int z){
	while(top[x]!=top[y]){
		if(deep[top[x]]<deep[top[y]]) swap(x,y);
		add(1,1,n,id[top[x]],id[x],z);
		x = fa[top[x]]; 
	}
	if(deep[x]>deep[y]) swap(x,y);
	// 即找lca
	add(1,1,n,id[x],id[y],z);
}
int query_range(int x,int y){
	int ans = 0;
	while(top[x]!=top[y]){
		if(deep[top[x]]<deep[top[y]]) swap(x,y);
		ans+=query(1,1,n,id[top[x]],id[x]);
		ans%=p;
		x = fa[top[x]]; 
	}
	if(deep[x]>deep[y]) swap(x,y);
	// 即找lca
	ans += query(1,1,n,id[x],id[y]);
	return ans%p;
}
void update_tree(int x,int z){
	add(1,1,n,id[x],siz[x]+id[x]-1,z);
}
int query_tree(int x){
	return query(1,1,n,id[x],siz[x]+id[x]-1)%p;
}
void solve() {  
	init();
	cin>>n>>m>>r>>p;
    rep(i,1,n) cin>>a[i];
    rep(i,1,n-1){
    	int u,v;cin>>u>>v;
    	addedge(u,v);
    	addedge(v,u);
    }
    dfs1(r,0);
    dfs2(r,r);
    build(1,1,n);
    rep(i,1,m){
    	int op,x,y,z;
    	cin>>op;
    	if(op==1){
    		cin>>x>>y>>z;
    		update_range(x,y,z);
    	}else if(op==2){
    		cin>>x>>y;
    		cout<<query_range(x,y)<<endl;
    	}else if(op==3){
    		cin>>x>>z;
    		update_tree(x,z);
    	}else{
    		cin>>x;
    		cout<<query_tree(x)<<endl;
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
