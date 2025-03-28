// Problem: F - x = a^b
// Contest: AtCoder - Denso Create Programming Contest 2024（AtCoder Beginner Contest 361）
// URL: https://atcoder.jp/contests/abc361/tasks/abc361_f
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
const int mx = 2e5+10;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  

  

void solve() {  
    i64 N;cin>>N;
    vector<i64> nums{1};
    for(i64 i=2;i*i*i<=N;i++){
    	i64 tmp = i*i*i;
    	while(1){
    		nums.pb(tmp);
    		if(tmp>N/i) break;
    		tmp*=i;
    	}
    }
    ranges::sort(nums);
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    i64 up = sqrt((double)N);
    while(up*up>N) up--;
    while((up+1)*(up+1)<=N) up++;
    i64 ans = nums.size()+up;
    for(auto& x:nums){
    	i64 y = sqrt((double)x);
    	while(y*y>x) y--;
    	while((y+1)*(y+1)<=x) y++;
    	if(y*y==x) ans--; 
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
