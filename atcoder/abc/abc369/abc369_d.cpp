// Problem: D - Bonus EXP
// Contest: AtCoder - AtCoder Beginner Contest 369
// URL: https://atcoder.jp/contests/abc369/tasks/abc369_d
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
//#define ll long long  
#define int long long  
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
    rep(i,0,n-1) cin>>a[i];
    int ans = 0;
    vector<vector<int>> memo(n,vector<int>(2,-1));
    auto dfs=[&](auto& self,int i,bool odd)->int{
    	if(i==n){
    		return 0;
    	}
    	int& res = memo[i][odd];
    	if(res!=-1) {
    		return res;
    	}
    	res = max(self(self,i+1,odd),self(self,i+1,!odd)+(odd?2:1)*a[i]);
    	return res;
    };
    cout<<dfs(dfs,0,false)<<endl;
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
    // cout<<pow(2,22)<<endl;  
    return 0;  
}
