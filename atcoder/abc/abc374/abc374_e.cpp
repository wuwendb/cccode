// Problem: E - Sensor Optimization Dilemma 2
// Contest: AtCoder - KEYENCE Programming Contest 2024（AtCoder Beginner Contest 374）
// URL: https://atcoder.jp/contests/abc374/tasks/abc374_e
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
    int n,x;cin>>n>>x;
    vector<int> a(n),b(n),p(n),q(n);
    rep(i,0,n-1){
    	cin>>a[i]>>p[i]>>b[i]>>q[i];
    	if(a[i]*q[i]<b[i]*p[i]) swap(a[i],b[i]),swap(p[i],q[i]);
    }
    auto check = [&](int mid){
    	int ans = 0;
    	rep(i,0,n-1){
    		int res=LLONG_MAX;
    		rep(j,0,a[i]){
    			int sum = j*q[i];
    			int remain = mid-j*b[i];
    			if(remain>0) {
    				sum+=1LL*(remain+a[i]-1)/a[i] * p[i];
    			}
    			res = min(sum,res);
    		}
    		ans+=res;
    	}
    	return ans<=x;
    };
    int l =0,r=1e9+10;
    while(l+1<r){
    	int mid = l+r>>1;
    	(check(mid)?l:r)=mid;
    }
    cout<<l<<endl;
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
