// Problem: C - Prepare Another Box
// Contest: AtCoder - AtCoder Beginner Contest 376
// URL: https://atcoder.jp/contests/abc376/tasks/abc376_c
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
    vector<int> a(n),b(n-1);
    rep(i,1,n) cin>>a[i-1];
    rep(i,1,n-1) cin>>b[i-1];
    ranges::sort(a,greater<>());
    ranges::sort(b,greater<>());
    int ans=-1;
    int j=0;
    for(int i=0,j=0;i<n;i++,j++){
    	if(a[i]>b[j]){
    		if(ans==-1){
    			ans = a[i];j--;
    		}else{
    			cout<<-1<<endl;return;
    		}
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
    // cout<<pow(2,22)<<endl;  
    return 0;  
}
