// Problem: G - AtCoder Tour
// Contest: AtCoder - AtCoder Beginner Contest 358
// URL: https://atcoder.jp/contests/abc358/tasks/abc358_g
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

const int dx[5]{0,0,-1,1,0};
const int dy[5]{-1,1,0,0,0};
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  

  
void solve() {  
    int h,w;
    i64 k;cin>>h>>w>>k;
    int si,sj;cin>>si>>sj;si--,sj--;
    vector<vector<i64>> a(h,vector<i64>(w));
    rep(i,0,h-1){
    	rep(j,0,w-1){
    		cin>>a[i][j];
    	}
    }
    vector<vector<vector<i64>>> dp(min(k,1LL*h*w)+1,vector<vector<i64>>(h,vector<i64>(w,-1e18)));
	i64 ans =0;
	dp[0][si][sj]=0;
	rep(i,0,min(k,1LL*h*w)-1){
		rep(j,0,h-1){
			rep(z,0,w-1){
				rep(t,0,4){
					int nx = j+dx[t];
					int ny = z+dy[t];
					if(nx>=0&&nx<h&&ny>=0&&ny<w){
						dp[i+1][nx][ny] = max(dp[i+1][nx][ny], dp[i][j][z]+a[nx][ny]);
					}
				}
			}
		}
	}
	rep(i,0,h-1){
		rep(j,0,w-1) ans = max(ans,dp[min(k,1LL*h*w)][i][j]+(k-min(k,1LL*h*w))*a[i][j]);
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
    return 0;  
}
