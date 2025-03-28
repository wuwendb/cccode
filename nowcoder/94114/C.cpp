// Problem: 小H学生物
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/94114/C
// Memory Limit: 512 MB
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
    int n,m,l;cin>>n>>m>>l;
	vector<bitset<100>> d(n);
    vector<vector<int>> g(n);
    rep(i,1,n-1){
    	int u,v;cin>>u>>v;u--,v--;
    	cin>>d[v];
    	g[u].pb(v);
    }
    auto dfs =[&](auto& dfs,int u)->void{
    	for(auto v:g[u]){
			d[v] ^= d[u];
			dfs(dfs,v);
    	}
    };
    dfs(dfs,0);
    vector<int> a(m);
    rep(i,1,m){
    	cin>>a[i-1];a[i-1]--;
    } 
    bitset<100> ans={0};
    if(m%2==1){
    	ans = d[a[0]]^d[a[m-1]];
    }else{
    	rep(i,1,m-2){
    		ans ^= d[a[i]];
    	}
    }
	cout<<ans.to_string().substr(100-l)<<endl;
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
