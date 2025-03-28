// Problem: P1113 杂务
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1113
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
const int mx = 1e4+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  
vector<int> g[mx];
int inde[mx],dp[mx],t[mx];
void solve() {  
    int n;cin>>n;
    queue<int> q;
    rep(i,1,n){
    	int index,len;cin>>index>>len;
    	t[i] = len;
    	int pre;
    	while(cin>>pre,pre!=0){
    		g[pre].push_back(i);
    		inde[i]++;
    	}
    	if(inde[i]==0){
    		q.push(i);
    		dp[i]=t[i];
    	}
    }
    while(!q.empty()){
    	int f = q.front();
    	q.pop();
    	for(auto i:g[f]){
    		dp[i] = max(dp[i],dp[f]+t[i]);
    		inde[i]--;
    		if(inde[i]==0) q.push(i);
    	}
    }
    int ans = 0;
    rep(i,1,n){
    	ans = max(ans,dp[i]);
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
    // cout<<pow(2,22)<<endl;  
    return 0;  
}
