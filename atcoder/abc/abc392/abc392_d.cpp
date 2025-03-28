// Problem: D - Doubles
// Contest: AtCoder - Japan Registry Services (JPRS) Programming Contest 2025#1 (AtCoder Beginner Contest 392)
// URL: https://atcoder.jp/contests/abc392/tasks/abc392_d
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

unordered_set<int> f[110];
void solve() {  
    int n;cin>>n;
	vector<vector<double>> pro(n,vector<double>(mx,0));
    rep(i,0,n-1){
    	int k;cin>>k;
    	rep(j,0,k-1){
    		int a;cin>>a;
    		pro[i][a] += 1.0/k;
    		f[i].insert(a);
    	}
    }
    double ans = 0;
    rep(i,0,n-1){
    	rep(j,i+1,n-1){
    		double res = 0;
    		for(auto k:f[i]){
				res += pro[i][k]*pro[j][k];
    		}
    		ans = max(ans, res);
    	}
    }
    cout<<ans<<endl;
}  
  
signed main() {  
    ios_base::sync_with_stdio(false);  
    cin.tie(nullptr);  
    int t=1;  
    // cin >> t; 
    cout<<fixed<<setprecision(15); 
    while (t--) {  
        solve();  
    } 
    return 0;  
}
