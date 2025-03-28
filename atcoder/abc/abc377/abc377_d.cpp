// Problem: D - Many Segments 2
// Contest: AtCoder - TOYOTA SYSTEMS Programming Contest 2024（AtCoder Beginner Contest 377)
// URL: https://atcoder.jp/contests/abc377/tasks/abc377_d
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
	int n,m;cin>>n>>m;
	vector<pii> g(n);
	rep(i,0,n-1) {
		cin>>g[i].second>>g[i].first;
	}
	ranges::sort(g);
	i64 ans = 0;
	int i=0,r=1,k=0;
	while(r<=m){
		while(k<n&&g[k].first<=r){
			i=max(i,g[k++].second);
		}
		ans+=r-i;
		r++;
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
