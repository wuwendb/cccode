// Problem: G - Suitable Edit for LIS
// Contest: AtCoder - AtCoder Beginner Contest 360
// URL: https://atcoder.jp/contests/abc360/tasks/abc360_g
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= int(b); ++i)  
#define rev(i, a, b) for (int i = int(a); i >= (b); --i) 
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
    vector<int> nums(n);
    rep(i,0,n-1) cin>>nums[i];
    vector<vector<int>> g(2);
    g[0].pb(INT_MIN);
    g[1].pb(INT_MIN);
    for (int x : nums) {
    	rev(j,1,0){
	        auto it = ranges::lower_bound(g[j], x);
	        if (it == g[j].end()) {
	            g[j].push_back(x);
	        } else {
	            *it = x;
	        }
    		if(j==1){
    			int last = g[0].back()+1;
    			if(g[0].size()<g[1].size()){
    				g[1][g[0].size()] = min(g[1][g[0].size()],last);
    			}else{
    				g[1].pb(last);
    			}
    		}
    	}
    }
    cout<<max(g[0].size()-1,g[1].size()-1)<<endl;

    
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
