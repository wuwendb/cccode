// Problem: D - K-th Nearest
// Contest: AtCoder - Japan Registry Services (JPRS) Programming Contest 2024#2 (AtCoder Beginner Contest 364)
// URL: https://atcoder.jp/contests/abc364/tasks/abc364_d
// Memory Limit: 1024 MB
// Time Limit: 3000 ms

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
    int n,q;cin>>n>>q;
    vector<int> a(n);
    rep(i,0,n-1) cin>>a[i];
    ranges::sort(a);
    auto check =[&](int b,int x,int k){
    	auto lcnt = ranges::lower_bound(a,b-x)-a.begin();
    	auto rcnt = ranges::upper_bound(a,b+x)-a.begin();
    	return rcnt-lcnt>=k;
    };
    rep(i,1,q){
    	int b,k;cin>>b>>k;
    	int l=-1,r=1e9;
    	while(l+1<r){
    		int mid = l+r>>1;
    		(check(b,mid,k)?r:l) = mid;
    	}
    	cout<<r<<endl;
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
