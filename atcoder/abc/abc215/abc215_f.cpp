// Problem: F - Dist Max 2
// Contest: AtCoder - AtCoder Beginner Contest 215
// URL: https://atcoder.jp/contests/abc215/tasks/abc215_f
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
    int n;cin>>n;
    vector<array<i64,2>> a(n);
    rep(i,0,n-1) cin>>a[i][0]>>a[i][1];
    ranges::sort(a);
    int l = 0,r = a[n-1][0]-a[0][0]+1;
    auto check = [&](int x){
    	i64 may=INT_MIN,miy = INT_MAX;
    	int j = 0;
    	for(int i=0;i<n;i++){
    		while(j<n&&a[j][0]<=a[i][0]-x){
    			may = max(may,a[j][1]);
    			miy = min(miy,a[j][1]);
    			j++;
    		}
    		if(may-a[i][1]>=x||a[i][1]-miy>=x){
    			return true;
    		}
    	}
    	return false;
    };
    while(l+1<r){
    	int mid =  (r-l)/2+l;
    	(check(mid)?l:r) = mid;  
    }
    cout<<l;
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
