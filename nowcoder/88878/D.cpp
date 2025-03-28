// Problem: ACM中的AC题
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/88878/D
// Memory Limit: 1048576 MB
// Time Limit: 6000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i) 
#define all(a) begin(a),end(a)
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
//#define ll long long  
#define int long long  
using namespace std;  
const int dx[4]{0,0,-1,1};
const int dy[4]{-1,1,0,0};
const int mx = 2e3+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  
char g[mx][mx];
int vis[mx][mx];
int n,m,x,y;
int dfs(int r,int c,bool ok1,bool ok2){
	if(ok1 && ok2) return 0;
	int res = INT_MAX;
	if(ok1||ok2){
		rep(k,0,3){
			int r1 = r+dx[k],c1 = c+dy[k];
			int r2 = 2*x-r1,c2 = 2*y-c1;
			if(!ok1&&(r1==0||r1==n+1 || c1==0||c1==m+1|| g[r1][c1] == '#')) continue;
			res = min(res,dfs(r1,c1,ok1||g[r1][c1]=='@',ok2||g[r2][c2]=='@')+1);
		}
	}else{
		rep(k,0,3){
			int r1 = r+dx[k],c1 = c+dy[k];
			int r2 = 2*x-r1,c2 = 2*y-c1;
			if(!ok1&&(r1==0||r1==n+1 || c1==0||c1==m+1|| g[r1][c1] == '#')||
			!ok2&&(r2==0||r2==n+1 || c2==0||c2==m+1 || g[r2][c2] == '#')||vis[r1][c1]) continue;
			res = min(res,dfs(r1,c1,ok1||g[r1][c1]=='@',ok2||g[r2][c2]=='@')+1);
		}
	}
	return res;
}
void solve() {  
    cin>>n>>m>>x>>y;
    rep(i,1,n){
    	rep(j,1,m){
    		cin>>g[i][j];
    	}
    }
    vis[x][y] = 1;
    int ans = dfs(x,y,false,false);
    cout<<((ans==INT_MAX)?(-1):ans)<<endl;
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
