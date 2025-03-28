// Problem: D - Count Simple Paths
// Contest: AtCoder - AtCoder Beginner Contest 378
// URL: https://atcoder.jp/contests/abc378/tasks/abc378_d
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
    int h,w,k;cin>>h>>w>>k;
    vector<vector<char>> g(h+2,vector<char>(w+2,'#'));
    rep(i,1,h){
    	rep(j,1,w) cin>>g[i][j];
    }
    vector<vector<int>> vis(h+2,vector<int>(w+2,0));
    int ans = 0;
    auto dfs = [&](auto self,int i,int j,int cnt){
    	if(cnt==k){
    		ans++;
    		return;	
    	}
    	vis[i][j]=1;
    	rep(t,0,3){
    		int x = i+dx[t];
    		int y = j+dy[t];
    		if(g[x][y]=='.'&&vis[x][y]==0){
    			self(self,x,y,cnt+1);
    		}
    	}
    	vis[i][j]=0;
    };
    rep(i,1,h){
    	rep(j,1,w){
    		if(g[i][j]!='#'){
    			dfs(dfs,i,j,0);
    		}
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
