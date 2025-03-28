// Problem: 学生分组
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/88527/B
// Memory Limit: 524288 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i) 
#define all(a) begin(a),end(a)
#define pii pair<int,int>
//#define ll long long  
#define int long long  
using namespace std;  
const int dx[4]{0,0,-1,1};
const int dy[4]{-1,1,0,0};
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  

  
void solve() {  
    int n;cin>>n;
    vector<int> a(n);
    rep(i,0,n-1) cin>>a[i];
    int low,up;cin>>low>>up;
    int sum = accumulate(all(a),0LL);
    if(sum>up*n||sum<low*n){
    	cout<<-1<<endl;return;
    } 
    int lsum=0,rsum=0;
    rep(i,0,n-1){
    	if(a[i]<low){
    		lsum+=low-a[i];
    	}
    	if(a[i]>up){
    		rsum+=a[i]-up;
    	}
    }
    cout<<max(lsum,rsum)<<endl;
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
    // cout<<pow(2,22)<<endl;  
    return 0;  
}
