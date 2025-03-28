// Problem: P10677 『STA - R6』inkar-usi
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P10677?contestId=158330
// Memory Limit: 512 MB
// Time Limit: 1000 ms

// #include <bits/stdc++.h>  
// #define endl "\n"  
// #define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
// #define rev(i, a, b) for (int i = (a); i >= (b); --i) 
// #define all(a) begin(a),end(a) 
// //#define ll long long  
// #define int long long  
// using namespace std;  
// const int dx[4]{0,0,-1,1};
// const int dy[4]{-1,1,0,0};
// const int mx = 2e3+5;  
// const int mod = 1e9+7;  
// const int MOD = 998244353;  
// //---------------------------------------------------------  
// int g[mx][mx];
// string work(int x,int y){
	// string res = "";
	// res.push_back(g[x][y]+'A' - 1);
	// int nmx=0;
	// rep(i,0,3){
		// int nnx = x+dx[i];
		// int nny = y+dy[i];
		// if(g[nnx][nny]>nmx){
			// nmx = g[nnx][nny];
		// }
	// }
	// if(nmx != g[x][y]&&nmx){
		// res.push_back(nmx+'A'-1);
	// }
	// return res;
// }  
// void solve() {  
    // int n,m;cin>>n>>m;
    // int maxx = 0;
    // vector<pair<int,int>> maxxpo;
    // rep(i,1,n){
    	// rep(j,1,m){
    		// char c;cin>>c;
    		// if(c!='#'){
	    		// g[i][j] = c - 'A' + 1;
	    		// if(maxx<g[i][j]){
	    			// maxxpo.clear();
	    			// maxx = g[i][j];
	    		// }
	    		// if(maxx==g[i][j]){
	    			// maxxpo.emplace_back(i,j);
	    		// }
    		// }
    	// }
    // }
    // string ans = "";
    // for(auto [x,y]:maxxpo){
    	// ans = max(ans,work(x,y));
    // }
    // cout<<ans<<endl;
// }  
//   
// signed main() {  
    // ios_base::sync_with_stdio(false);  
    // cin.tie(nullptr);  
    // int t=1;  
    // // cin >> t; 
    // cout<<fixed<<setprecision(1); 
    // while (t--) {  
        // solve();  
    // }  
    // // cout<<pow(2,22)<<endl;  
    // return 0;  
// }

//ac
#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define I return
#define love 0
#define FIRESTARS ;
string ans,space;
int n,m,dx[]={0,1,0,-1},dy[]={1,0,-1,0};
char a[1005][1005],maxn=0;
signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
    	cin>>a[i][j];
    	maxn=max(maxn,a[i][j]);
	}
	ans=space+maxn;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    if(a[i][j]==maxn)
	for(int k=0;k<4;k++)
    {
    	int xx=dx[k]+i,yy=dy[k]+j;
    	if(xx>=1&&yy>=1&&xx<=n&&yy<=m&&a[xx][yy]!='#')
    	ans=max(ans,space+a[i][j]+a[xx][yy]);
	}
	if(ans.size()==1)cout<<ans;
	else
	{
		if(ans[0]==ans[1])cout<<ans[0];
		else cout<<ans;
	}
}