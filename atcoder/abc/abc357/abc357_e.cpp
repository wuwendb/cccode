// Problem: E - Reachability in Functional Graph
// Contest: AtCoder - SuntoryProgrammingContest2024（AtCoder Beginner Contest 357）
// URL: https://atcoder.jp/contests/abc357/tasks/abc357_e
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
    vector<int> a(n);
    rep(i,0,n-1){
    	cin>>a[i];a[i]--;	
	}
	i64 ans = 0;
	vector<int> sum(n,-1);
	auto check = [&](int u){
		vector<int> vis{u};
		map<int,int> mp{{u,0}};
		while(!mp.contains(a[u])){
			if(sum[a[u]]!=-1){
				rep(i,0,vis.size()-1){
					sum[vis[i]] = sum[a[u]]+vis.size()-i;
				}
				return;
			}
			u = a[u];
			mp[u]=vis.size();
			vis.pb(u);
		}
		int m = vis.size();
		int loop = m-mp[a[u]];
		rep(i,0,m-1){
			if(i<mp[a[u]]){
				sum[vis[i]] = m-i;
			}else{
				sum[vis[i]]=loop;
			}
		}
	};
	rep(i,0,n-1){
		if(sum[i]==-1){
			check(i);
		}
	}
	ans =accumulate(sum.begin(),sum.end(),0LL);
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
