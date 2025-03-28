// Problem: 迷宫
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/88455/C
// Memory Limit: 524288 MB
// Time Limit: 2000 ms

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
const int mx = 1000+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  
int g[mx][mx],vis[mx][mx];  
int n,m;
int minx1,maxx1,miny1,maxy1;
int minx2,maxx2,miny2,maxy2;
pair<int,int> s,e;
void dfs1(int i,int j){
	vis[i][j] = 1;
	if(i==e.first&&j==e.second){
		cout<<"YES"<<endl;
		exit(0);
	}
	minx1 = min(minx1,i);
	maxx1 = max(maxx1,i);
	miny1 = min(miny1,j);
	maxy1 = max(maxy1,j);
	rep(k,0,3){
		int ni = i+dx[k];
		int nj = j+dy[k];
		if(g[ni][nj]!=0&&!vis[ni][nj]){
			dfs1(ni,nj);
		}
	}
}
void dfs2(int i,int j){
	vis[i][j] = 1;
	minx2 = min(minx2,i);
	maxx2 = max(maxx2,i);
	miny2 = min(miny2,j);
	maxy2 = max(maxy2,j);
	rep(k,0,3){
		int ni = i+dx[k];
		int nj = j+dy[k];
		if(g[ni][nj]!=0&&!vis[ni][nj]){
			dfs2(ni,nj);
		}
	}
}
void solve() {  
    cin>>n>>m;
    minx1=n+1,maxx1=0,miny1=m+1,maxy1=0;
    minx2=n+1,maxx2=0,miny2=m+1,maxy2=0;
    rep(i,1,n){
    	rep(j,1,m){
    		char c;cin>>c;
    		if(c=='#'){
    			continue;
			}
			g[i][j] = 1;
    		if(c=='S'){
    			s.first = i,s.second = j;
    		}else if(c=='E'){
    			e.first = i,e.second = j;
    		}
    	}
    }
    dfs1(s.first,s.second);
    dfs2(e.first,e.second);
    if(max(minx1,minx2)<=min(maxx1,maxx2)+1||max(miny1,miny2)<=min(maxy1,maxy2)+1){
    	cout<<"YES"<<endl;
    }else{
    	cout<<"NO"<<endl;
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
