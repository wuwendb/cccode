// Problem: P3128 [USACO15DEC] Max Flow P
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3128
// Memory Limit: 125 MB
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
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  
vector<int> g[mx];  
int depth[mx], fa[mx][22], lg[mx];  
void dfs(int x, int fath) {  
    fa[x][0] = fath; depth[x] = depth[fath] + 1;  
    for(int i = 1; i <= lg[depth[x]]; ++i)  
        fa[x][i] = fa[fa[x][i-1]][i-1];  
    for(int y:g[x]){  
        if(y!=fath) {  
            dfs(y,x);  
        }  
    }  
}  
int LCA(int x, int y) {  
    if(depth[x] < depth[y]) swap(x, y);  
    while(depth[x] > depth[y])  
        x = fa[x][lg[depth[x]-depth[y]] - 1];  
    if(x == y) return x;  
    for(int k = lg[depth[x]] - 1; k >= 0; --k)  
        if(fa[x][k] != fa[y][k])  
            x = fa[x][k], y = fa[y][k];  
    return fa[x][0];  
}  
int diff[mx];
void solve() {  
    int n,k;cin>>n>>k;  
    for(int i = 1; i <= n; ++i)  
        lg[i] = lg[i-1] + (1 << lg[i-1] == i);  
    rep(i,1,n-1){  
        int a,b;cin>>a>>b;  
        g[a].push_back(b);  
        g[b].push_back(a);  
    }  
    dfs(1,0);  
    while(k--){  
        int a,b;cin>>a>>b;  
        int r = LCA(a,b);
        diff[a]++,diff[b]++,diff[r]--,diff[fa[r][0]]--;  
    }  
    int ans = 0;
    function<int(int,int)> dfs = [&](int x,int fath)->int{
		int res = diff[x];
    	for(int y:g[x]){
    		if(y!=fath){
    			res+=dfs(y,x);
    		}
    	}
    	ans = max(ans,res);
    	return res;
    };
    dfs(1,0);
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
