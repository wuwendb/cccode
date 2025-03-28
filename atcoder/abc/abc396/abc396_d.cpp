// Problem: D - Minimum XOR Path
// Contest: AtCoder - AtCoder Beginner Contest 396
// URL: https://atcoder.jp/contests/abc396/tasks/abc396_d
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
    int N,M;cin>>N>>M;
    vector<vector<pair<int,i64>>> adj(N);
    rep(i,0,M-1){
    	int u,v;
    	i64 w;
    	cin>>u>>v>>w;
    	u--,v--;
    	adj[u].pb({v,w});
    	adj[v].pb({u,w});
    }
    i64 ans = LLONG_MAX;
    vector<int> vis(N,0);
    vis[0]=1;
    auto dfs = [&](auto &&self, int x, int p = -1, i64 sum)->void{
    	if(x == N-1){
    		ans = min(ans, sum);
    		return;
    	}
    	for(auto [y,w]:adj[x]){
    		if(y==p||vis[y]==1){
    			continue;
    		}
    		vis[y]=1;
    		self(self, y , x, sum^w);
    		vis[y]=0;
    	}
    };
    dfs(dfs,0,-1,0);
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
