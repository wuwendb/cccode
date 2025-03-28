// Problem: E - Minimize Sum of Distances
// Contest: AtCoder - Toyota Programming Contest 2024#4（AtCoder Beginner Contest 348）
// URL: https://atcoder.jp/contests/abc348/tasks/abc348_e
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
const int mx = 1e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  

void solve() {  
    int n;cin>>n;
    vector<vector<int>> g(n);
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;a--,b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<i64> a(n);
    vector<i64> ans(n),sum(n);
    rep(i,0,n-1){
    	cin>>a[i];
    }
    auto dfs = [&](auto&& self, int i,int pa,int dep)->void{
    	ans[0] += a[i]*dep;
    	sum[i] = a[i];
    	for(auto j:g[i]){
    		if(j!=pa){
    			self(self,j,i,dep+1);
    			sum[i] += sum[j];
    		}
    	}
    };
    dfs(dfs,0,-1,0);
    auto reroot = [&](auto&& self, int i,int pa)->void{
    	for(auto j:g[i]){
    		if(j!=pa){
    			ans[j] = ans[i]-sum[j]+(sum[0]-sum[j]);
    			self(self,j,i);
    		}
    	}
    };
    reroot(reroot, 0, -1);
    cout<<ranges::min(ans)<<endl;
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
