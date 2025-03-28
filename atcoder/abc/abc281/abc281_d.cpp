// Problem: D - Max Multiple
// Contest: AtCoder - AtCoder Beginner Contest 281
// URL: https://atcoder.jp/contests/abc281/tasks/abc281_d
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
    int n,k,d;cin>>n>>k>>d;
    vector<int> a(n);
    rep(i,0,n-1) cin>>a[i];
    vector<vector<i64>> f(k+1,vector<i64>(d,LLONG_MIN));
    f[0][0] = 0;
    rep(i,0,n-1){
    	rev(j,k-1,0){
    		rep(t,0,d-1){
		    	f[j+1][(t+a[i])%d] = max(f[j+1][(t+a[i])%d], f[j][t]+a[i]);		
    		}
    	}
    }
    if(f[k][0]<0){
    	cout<<-1<<endl;
    	return;
    }
    cout<<f[k][0]<<endl;
    
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
