// Problem: C - Enumerate Sequences
// Contest: AtCoder - AtCoder Beginner Contest 367
// URL: https://atcoder.jp/contests/abc367/tasks/abc367_c
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
    void solve() {  
    int n,k;cin>>n>>k;
    vector<int> r(n);rep(i,0,n-1) cin>>r[i];
    vector<int> tmp(n);
    auto dfs = [&](auto& self,int i,int sum){
    	if(i==n){
    		if(sum%k==0){
    			rep(j,0,n-1){
    				cout<<tmp[j]<<" \n"[j==n-1];
    			}
    		}
    		return;
    	}
    	for(int j=1;j<=r[i];j++){
    		tmp[i] = j;
    		self(self,i+1,sum+j);
    	}
    };
    dfs(dfs,0,0);
}  
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
