// Problem: P1685 游览
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1685
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
const int mx = 2e5+5;  
const int mod = 10000;  
const int MOD = 998244353;  
//---------------------------------------------------------  
vector<pair<int,int>> g[mx];
int inde[mx];
int dp[mx][2];
int ans = 0;
int n,m,s,t,timeplus;
void dfs(int x){
	for(auto [y,tt]:g[x]){
		dp[y][0] = (dp[y][0]+dp[x][0])%mod;
		dp[y][1] = (dp[y][1]+dp[x][1]+dp[x][0]*tt)%10000;
		inde[y]--;
		if(!inde[y]) dfs(y);
	}
	
}
void solve() {  
    cin>>n>>m>>s>>t>>timeplus;
    rep(i,1,m){
    	int x,y,tt;
    	cin>>x>>y>>tt;
    	g[x].emplace_back(y,tt);
    	inde[y]++;
    }
    dp[s][0]=1;
    dfs(s);
    cout<<((dp[t][0]-1)*timeplus+dp[t][1])%mod<<endl;
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
