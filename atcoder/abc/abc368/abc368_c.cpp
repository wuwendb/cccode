// Problem: C - Triple Attack
// Contest: AtCoder - Hitachi Vantara Programming Contest 2024（AtCoder Beginner Contest 368）
// URL: https://atcoder.jp/contests/abc368/tasks/abc368_c
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
    int ans =0;
    int n;cin>>n;
    int start=0;
    rep(i,1,n){
    	int h;cin>>h;
    	ans += h/5*3;
    	int remain = h%5;
    	while(remain>0){
    		if(start==0||start==1){
    			remain--;
    		}else{
    			remain-=3;
    		}
    		start++;
    		ans++;
    		start%=3;
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
