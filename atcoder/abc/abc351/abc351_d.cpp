// Problem: D - Grid and Magnet
// Contest: AtCoder - AtCoder Beginner Contest 351
// URL: https://atcoder.jp/contests/abc351/tasks/abc351_d
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
    int n,m;cin>>n>>m;
    vector<vector<char>> g(n,vector<char>(m,'#'));
    rep(i,1,n){
    	rep(j,1,m){
    		cin>>g[i-1][j-1];
    	}
    }
    auto check = [&](int i,int j){
    	return i>=0&&i<n&&j>=0&&j<m;
    };
    vector<vector<int>> stop(n,vector<int>(m,0));
    rep(i,0,n-1){
    	rep(j,0,m-1){
    		if(g[i][j]=='#'){
    			rep(k,0,3){
    				int x = i+dx[k];
    				int y = j+dy[k];
    				if(check(x,y)){
    					stop[x][y]=1;
    				}
    			}
    		}
    	}
    }
    vector<vector<int>> vis(n,vector<int>(m,-1));
    int ans = 0;
    rep(i,0,n-1){
    	rep(j,0,m-1){
    		if(g[i][j]!='#'&&vis[i][j]==-1){
    			int res = 0;
    			queue<pii> q;
    			q.push({i,j});
    			vis[i][j] = (i<<10)+j;
    			while(!q.empty()){
    				auto [x,y] = q.front();q.pop();
    				res++;
    				if(stop[x][y]) continue;
    				rep(k,0,3){
    					int nx = x+dx[k];
	    				int ny = y+dy[k];
	    				if(check(nx,ny)&&vis[nx][ny]!=(i<<10)+j){
	    					vis[nx][ny]=(i<<10)+j;
	    					q.push({nx,ny});
	    				}
    				}
    			}
    			ans = max(ans,res);
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
