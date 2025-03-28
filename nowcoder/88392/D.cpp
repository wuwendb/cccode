// Problem: 构造故事
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/88392/D
// Memory Limit: 524288 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i) 
#define all(a) begin(a),end(a) 
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
    vector<int> a(n);rep(i,1,n) cin>>a[i-1];
    sort(all(a),greater<>());
    int i = 0;
    while(i+2<n&&a[i]>=a[i+1]+a[i+2]){
    	i++;
    }
    if(i==n-2){
    	cout<<-1<<endl;
    }else{
    	cout<<a[i]+a[i+1]+a[i+2]<<endl;
    }
}  
  
signed main() {  
    ios_base::sync_with_stdio(false);  
    cin.tie(nullptr);  
    int t=1;  
    cin >> t; 
    cout<<fixed<<setprecision(1); 
    while (t--) {  
        solve();  
    }  
    // cout<<pow(2,22)<<endl;  
    return 0;  
}
