// Problem: D - Permutation Subsequence
// Contest: AtCoder - AtCoder Beginner Contest 352
// URL: https://atcoder.jp/contests/abc352/tasks/abc352_d
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
    int n,k;cin>>n>>k;
    unordered_map<int,int> mp;
    rep(i,0,n-1){
    	int x;cin>>x;x--;
    	mp[x]=i;
    }
	priority_queue<pii,vector<pii>,greater<>> pq1,pq2;
	int ans = 1e9;
    rep(i,0,n-1){
    	pq1.push({mp[i],i});
    	pq2.push({-mp[i],i});
    	if(i>=k-1){
    		while(pq1.top().second<i-k+1){
    			pq1.pop();
    		}
    		while(pq2.top().second<i-k+1){
    			pq2.pop();
    		}
    		ans = min(-pq2.top().first-pq1.top().first,ans);
    	}
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
