// Problem: P2607 [ZJOI2008] 骑士
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2607
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
const int mx = 1e6+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  
int val[mx],vis[mx],fa[mx];
vector<int> g[mx];
int dp[mx][2],root;
void dfs(int x){
	dp[x][0] = 0;
	dp[x][1] = val[x];
	vis[x] = 1;
	for(auto y:g[x]){
		if(y == root){
			continue;
		}
		dfs(y);
		dp[x][1] += dp[y][0];
		dp[x][0] += max(dp[y][0],dp[y][1]);
	}
}
int find(int x){
	vis[x]=true;
	if(!vis[fa[x]]){
		return find(fa[x]);
	}else{
		return fa[x];
	}
}
int cal(int x){
	int res = 0;
	root = find(x);
	dfs(root);
	res = max(res,dp[root][0]);
	root = fa[root];
	dfs(root);
	res = max(res,dp[root][0]);
	return res;
}
void solve() {  
    int n,v;cin>>n;
    rep(i,1,n){
    	cin>>val[i]>>v;
    	g[v].push_back(i);
    	fa[i] = v;
    }
    int ans = 0;
    rep(i,1,n){
    	if(!vis[i]) ans += cal(i);
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
