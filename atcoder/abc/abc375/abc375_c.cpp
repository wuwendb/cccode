// Problem: C - Spiral Rotation
// Contest: AtCoder - Panasonic Programming Contest 2024（AtCoder Beginner Contest 375）
// URL: https://atcoder.jp/contests/abc375/tasks/abc375_c
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
    vector<vector<char>> A(n+1,vector<char>(n+1));
    rep(i,1,n){
    	rep(j,1,n){
    		cin>>A[i][j];
    	}
    }
    vector<vector<char>> B(A);
    auto trans = [&](int x,int y,int t)->pair<int,int>{
    	int tx=x,ty=y;
    	while(t--){
    		tx = n+1-y;
    		ty = x;
    		x =tx;
    		y =ty;
    	}
    	return {x,y};
    };
    rep(k,1,n/2){
    	int t =k%4;
    	pair<int,int> xy;
		rep(i,k,n+1-k){
			xy =trans(i,k,t);
    		B[i][k] = A[xy.first][xy.second];
    		xy =trans(i,n+1-k,t);
    		B[i][n+1-k] = A[xy.first][xy.second];
    		xy =trans(k,i,t);
    		B[k][i] = A[xy.first][xy.second];
    		xy =trans(n+1-k,i,t);
    		B[n+1-k][i] = A[xy.first][xy.second];
    	}
    	A.assign(B.begin(),B.end());
    }
    rep(i,1,n){
    	rep(j,1,n){
    		cout<<B[i][j];
    	}
    	cout<<"\n";
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
