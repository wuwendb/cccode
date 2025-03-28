// Problem: F - Add One Edge 2
// Contest: AtCoder - AtCoder Beginner Contest 378
// URL: https://atcoder.jp/contests/abc378/tasks/abc378_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i) 
#define all(a) begin(a),end(a)
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back

#define int long long
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
    vector<vector<int>> g(n);
    rep(i,1,n-1){
    	int u,v;cin>>u>>v;
    	u--,v--;
    	g[u].pb(v);
    	g[v].pb(u);
    }
    vector<int> vis(n);
    int ans = 0;
    auto dfs = [&](auto& self,int u)->int{
    	vis[u]=1;
    	vector<int> count;
    	for(auto v:g[u]){
    		if(vis[v]==0&&g[v].size()==3){
    			count.pb(self(self,v));
    		}else if(g[v].size()==2){
    			count.pb(1);
    		}
    	}
    	int res=0;
    	int sum = accumulate(count.begin(),count.end(),0);
    	for(auto x:count){
    		res += x*(sum-x);
    	}
    	ans += res/2;
    	return sum;
    };
    rep(i,0,n-1){
    	if(g[i].size()==3&&vis[i]==0){
    		dfs(dfs,i);
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
    return 0;  
}
