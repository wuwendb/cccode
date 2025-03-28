// Problem: D - Cuboid Sum Query
// Contest: AtCoder - AtCoder Beginner Contest 366
// URL: https://atcoder.jp/contests/abc366/tasks/abc366_d
// Memory Limit: 1024 MB
// Time Limit: 3000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i)  
//#define ll long long  
#define int long long  
using namespace std;  
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  

  
void solve() {  
    int n;cin>>n;
    vector<vector<vector<int>>> g(n+1,vector<vector<int>>(n+1,vector<int>(n+1,0)));
    rep(i,1,n){
    	rep(j,1,n){
    		rep(k,1,n){
    			int val;cin>>val;
    			g[i][j][k] = g[i][j-1][k]+g[i][j][k-1]-g[i][j-1][k-1]+val + g[i-1][j][k]-g[i-1][j-1][k]-g[i-1][j][k-1]+g[i-1][j-1][k-1];
    		}
    	}
    }
    
    int q;cin>>q;
    rep(i,1,q){
    	int lx1,lx2,ly1,ly2,lz1,lz2;
    	cin>>lx1>>lx2>>ly1>>ly2>>lz1>>lz2;
    	cout<<(g[lx2][ly2][lz2]+g[lx2][ly1-1][lz1-1]-g[lx2][ly1-1][lz2]-g[lx2][ly2][lz1-1])
    			-
    	(g[lx1-1][ly2][lz2]+g[lx1-1][ly1-1][lz1-1]-g[lx1-1][ly1-1][lz2]-g[lx1-1][ly2][lz1-1])<<endl;
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
