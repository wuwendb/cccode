// Problem: T511486 【入门赛】E 距离
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/T511486?contestId=197857
// Memory Limit: 512 MB
// Time Limit: 1000 ms

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
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  
int g[110][110];
  
void solve() {  
    int n,m;cin>>n>>m;
    int ans;
    rep(i,1,m){
    	ans = 0;
    	int op,a,b,c;cin>>op>>a>>b>>c;
    	if(op==1){
    		g[a][b] += c;
    	}else{
    		g[a][b] -= c;
    	}
    	rep(i,1,n){
	    	rep(j,1,n){
	    		ans = max(ans,g[i][j]);
	    	}
	    }
	    cout<<ans<<endl;
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
