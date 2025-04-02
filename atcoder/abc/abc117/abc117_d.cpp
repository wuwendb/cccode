// Problem: D - XXOR
// Contest: AtCoder - AtCoder Beginner Contest 117
// URL: https://atcoder.jp/contests/abc117/tasks/abc117_d
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

void solve() {  
    int n;i64 k;cin>>n>>k;
    vector<i64> a(n);
    rep(i,0,n-1){
    	cin>>a[i];
    }
    int klen =bit_width((u64)k)-1;
    int len = bit_width((u64)ranges::max(a))-1;
    int l = max(len,klen);
    vector<int> ma(l+1,0);
    rev(i,l,0){
    	int ones = 0;
    	rep(j,0,n-1){
    		if((a[j]>>i)&1){
    			ones++;
    		}
    	}
    	ma[i] = ones;
    }
    vector<array<i64,2>> memo(l+1,array<i64,2>{-1,-1});
    auto dfs = [&](auto&& self, int i,bool islimited)->i64{
    	if(i<0){
    		return 0;
    	}
    	if(memo[i][islimited]!=-1){
    		return memo[i][islimited];
    	}
    	i64 res = 0;
    	int high = islimited?(k>>i&1):1;
    	array<int,2> cnt{ma[i],n-ma[i]};
    	for(int j=0;j<=high;j++){
    		res = max(res, self(self,i-1,islimited&&j==high)+(1LL<<i)*cnt[j]);
    	}
		memo[i][islimited] = res;
		return res;
    };
    cout<<dfs(dfs, l, true)<<endl;
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
