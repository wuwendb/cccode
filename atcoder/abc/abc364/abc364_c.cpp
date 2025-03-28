// Problem: C - Minimum Glutton
// Contest: AtCoder - Japan Registry Services (JPRS) Programming Contest 2024#2 (AtCoder Beginner Contest 364)
// URL: https://atcoder.jp/contests/abc364/tasks/abc364_c
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
    i64 x,y;cin>>x>>y;
    vector<pair<i64,i64>> dishes(n);
    rep(i,1,n) cin>>dishes[i-1].first;
    rep(i,1,n) cin>>dishes[i-1].second;
    ranges::sort(dishes,greater<>());
    i64 sum=0;
    int ans=n;
    rep(i,0,n-1){
    	sum+=dishes[i].first;
    	if(sum>x){
    		ans =min(ans,i+1);
    		break;
    	}
    }
    ranges::sort(dishes,[](auto& p1,auto& p2){
    	return p1.second>p2.second;
    });
    sum=0;
    rep(i,0,n-1){
    	sum+=dishes[i].second;
    	if(sum>y){
    		ans =min(ans,i+1);
    		break;
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
