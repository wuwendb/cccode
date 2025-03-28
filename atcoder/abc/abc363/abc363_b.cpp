// Problem: B - Japanese Cursed Doll
// Contest: AtCoder - AtCoder Beginner Contest 363
// URL: https://atcoder.jp/contests/abc363/tasks/abc363_b
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
    int n,t,p;cin>>n>>t>>p;
    vector<int> a(n);
    rep(i,0,n-1) cin>>a[i];
    ranges::sort(a);
    int l=-1,r=200;
    auto check = [&](int x){
    	auto ind = a.end()-ranges::lower_bound(a,t-x);
    	return ind>=p;
    };
    while(l+1<r){
    	int mid =l+r>>1;
    	(check(mid)?r:l)=mid;
    }
    cout<<r<<endl;
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
