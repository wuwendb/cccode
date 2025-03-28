// Problem: P2602 [ZJOI2010] 数字计数
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2602
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
int nums[mx],cur;
int memo[15][mx];
int dfs(int i,int sum,bool lead,bool islimit){
	if(i==0){
		return sum;
	}
	if(!islimit&&!lead&&memo[i][sum]!=-1){
		return memo[i][sum];
	}
	int up = islimit?nums[i]:9;
	int res = 0;
	for(int d=0;d<=up;d++){
		res += dfs(i-1,sum+(d==cur&&!(d==0&&lead)),lead&&d==0,islimit&&up==d);
	}
	if(!islimit&&!lead){
		memo[i][sum] = res;
	}
	return res;
}
int work(int x){
	int len = 0;
	while(x){
		nums[++len] = x%10;
		x/=10;
	}
	memset(memo,-1,sizeof(memo));
	return dfs(len,0,true,true);
}
  
void solve() {  
    int a,b;cin>>a>>b;
    rep(i,0,9){
    	cur = i;
    	cout<<work(b)-work(a-1)<<" \n"[i==9];
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
