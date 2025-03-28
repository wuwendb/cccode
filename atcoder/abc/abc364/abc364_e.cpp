// Problem: E - Maximum Glutton
// Contest: AtCoder - Japan Registry Services (JPRS) Programming Contest 2024#2 (AtCoder Beginner Contest 364)
// URL: https://atcoder.jp/contests/abc364/tasks/abc364_e
// Memory Limit: 1024 MB
// Time Limit: 3000 ms

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
    int n,x,y;cin>>n>>x>>y;
    vector<int> a(n),b(n);
    rep(i,1,n) cin>>a[i-1]>>b[i-1];
	vector dp(n+1,vector<int>(x+1,y+1));
	dp[0][0]=0;
	rep(i,0,n-1){
		rev(j,i,0){
			rev(k,x,a[i]){
				dp[j+1][k] = min(dp[j+1][k],dp[j][k-a[i]]+b[i]);
			}
		}
	}
	int ans =0;
	rev(i,n,0){
		rep(k,0,x){
			if(dp[i][k]<=y){
				ans = max(i+1,ans);
			}
		}
	}
	cout<<min(ans,n)<<endl;
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
