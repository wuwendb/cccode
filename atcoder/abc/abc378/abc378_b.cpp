// Problem: B - Garbage Collection
// Contest: AtCoder - AtCoder Beginner Contest 378
// URL: https://atcoder.jp/contests/abc378/tasks/abc378_b
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
    vector<int> q(n),r(n);
    rep(i,0,n-1) cin>>q[i]>>r[i];
    int Q;cin>>Q;
    rep(i,1,Q){
    	int t,d;cin>>t>>d;t--;
    	if(d%q[t]==r[t]){
    		cout<<d<<endl;
    	}else if(d%q[t]>r[t]){
    		cout<<(d/q[t]+1)*q[t]+r[t]<<endl;
    	}else{
    		cout<<d/q[t]*q[t]+r[t]<<endl;
    	}
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
