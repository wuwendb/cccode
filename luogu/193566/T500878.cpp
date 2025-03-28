// Problem: T500878 【MX-J3-T2】Substring
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/T500878?contestId=193566
// Memory Limit: 512 MB
// Time Limit: 1000 ms

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
    int n,q;cin>>n>>q;
    vector<pair<int,int>> a(n+1);
    rep(i,1,n){
    	cin>>a[i].first;
    	a[i].second = i;
    }
    ranges::sort(a);
    vector<int> p(n+1);
    p[0]=0;
    rep(i,1,n){
    	p[i] = n-a[i].second+1+p[i-1];
    }
    rep(i,1,q){
    	int k;cin>>k;
	    int index = lower_bound(all(p),k)-p.begin();
	    cout<<a[index].second<<" "<<a[index].second+k-1-p[index-1]<<endl;
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
    // cout<<pow(2,22)<<endl;  
    return 0;  
}
