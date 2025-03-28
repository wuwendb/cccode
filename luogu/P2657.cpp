// Problem: P2657 [SCOI2009] windy 数
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2657
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
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  
int num[mx];
int memo[mx][10];
int dfs(int i,int last,bool lead,bool islimit){
	if(i==0) return 1;
	if(!islimit&&!lead&&memo[i][last]!=-1){
		return memo[i][last];
	}
	int up = islimit?num[i]:9;
	int res = 0;
	for(int d = 0;d<=up;d++){
		if(abs(d-last)>=2) res += dfs(i-1,(lead&&d==0)?-2:d,lead&&d==0,islimit&&d==up);
	}
	if(!islimit&&!lead){
		memo[i][last] = res;
	}
	return res;
}
int work(int x){
	int len = 0;
	while(x){
		num[++len] = x%10;
		x/=10;
	}
	memset(memo,-1,sizeof(memo));
	return dfs(len,-2,true,true);
}
  
void solve() {  
    int a,b;cin>>a>>b;
    cout<<work(b)-work(a-1)<<endl;
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
