// Problem: E - GCD of Subset
// Contest: AtCoder - AtCoder Beginner Contest 393
// URL: https://atcoder.jp/contests/abc393/tasks/abc393_e
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
const int mx = 1e6+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  

  
void solve() {  
    int k,n;cin>>n>>k;
    vector<int> a(n);
    vector<int> mp(mx);
    rep(i,0,n-1){
    	cin>>a[i];
    	mp[a[i]]++;
    } 
    vector<vector<int>> factor(mx);
    vector<int> father(mx);
    rep(i,1,mx-1){
    	for(int j=i;j<mx;j+=i){
    		factor[j].pb(i);
    		father[i] += mp[j];
    	}
    }
    rep(i,1,mx-1) ranges::reverse(factor[i]);
    rep(i,0,n-1){
    	for(auto x:factor[a[i]]){
    		if(father[x]>=k){
    			cout<<x<<endl;
    			break;
    		}
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
