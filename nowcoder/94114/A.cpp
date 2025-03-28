// Problem: 小H学语文
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/94114/A
// Memory Limit: 512 MB
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
    vector<int> h(n);
    rep(i,1,n) cin>>h[i-1];
    vector<int> ind(n);
    iota(ind.begin(),ind.end(),0);
    ranges::sort(ind,[&](auto x,auto y){
    	return h[x]>h[y];
    });
    i64 ans=0;
    int k=-1;
    rep(i,0,n-1){
    	i64 sum = 1LL*(i+1)*(i+1)*h[ind[i]];
    	if(sum>ans){
    		ans = sum;
            k=i;
    	}
    }
    vector<int> res(ind.begin(),ind.begin()+k+1);
    ranges::sort(res);
    cout<<res.size()<<endl;
    rep(i,0,res.size()-1) cout<<res[i]+1<<" \n"[i==res.size()-1];
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
