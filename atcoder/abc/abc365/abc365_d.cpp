// Problem: D - AtCoder Janken 3
// Contest: AtCoder - Toyota Programming Contest 2024#8（AtCoder Beginner Contest 365）
// URL: https://atcoder.jp/contests/abc365/tasks/abc365_d
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
	int n;cin>>n;
    string s;cin>>s;
    vector<vector<int>> dp(n,vector<int>(2,0));
    dp[0][1]=1;
    auto check = [&](char c1,char c2){
    	return c1=='R'&&c2=='P'||c1=='P'&&c2=='S'||c1=='S'&&c2=='R';
    };
    rep(i,1,n-1){
    	if(s[i]!=s[i-1]) dp[i][0] = max(dp[i][0],dp[i-1][0]),dp[i][1] = max(dp[i][1],dp[i-1][1]+1);
    	if(!check(s[i-1],s[i])) dp[i][0] = max(dp[i][0],dp[i-1][1]);
    	if(!check(s[i],s[i-1])) dp[i][1] = max(dp[i][1],dp[i-1][0]+1);
    }
    cout<<max(dp[n-1][0],dp[n-1][1])<<endl;;
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
