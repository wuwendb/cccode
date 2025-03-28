// Problem: E - Max/Min
// Contest: AtCoder - AtCoder Beginner Contest 356
// URL: https://atcoder.jp/contests/abc356/tasks/abc356_e
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
    vector<int>a(n);rep(i,0,n-1)cin>>a[i];
    i64 ans = 0;
    int m = ranges::max(a);
    vector<int> cnt(m+1);
    for(auto x:a) cnt[x]++;
    vector<int> pre(m+1);
    rep(i,1,m){
    	pre[i] = pre[i-1]+cnt[i];
    }
    rep(i,1,m){
    	ans += 1LL*cnt[i]*(cnt[i]-1)/2;
    	for(int j=i;j<=m;j+=i){
    		int count = pre[min(j+i-1,m)]-pre[max(i,j-1)];
    		ans += 1LL*count*cnt[i]*j/i;
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
