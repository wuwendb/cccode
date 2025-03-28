// Problem: P2024 [NOI2001] 食物链
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2024
// Memory Limit: 125 MB
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
const int mx = 3e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  
int fa[mx];
int find(int x) {  
	return fa[x] == x ? x : fa[x] = find(fa[x]);  
}  
void dsu(){
	iota(begin(fa), end(fa), 0);
}  
  
void solve() {  
	dsu();
    int n,k;cin>>n>>k;
    int ans = 0;
	rep(i,1,k){
		int op,xx,yy;cin>>op>>xx>>yy;
		if(xx>n||yy>n||op==2&&xx==yy){
			ans++;continue;
		}
		
		if(op==1){
			int x= find(xx);
			int y = find(yy);
			int sx = find(xx+n);
			int sy = find(yy+n);
			int bx = find(xx+2*n);
			int by = find(yy+2*n);
			if(x==sy||x==by||y==sx||y==bx){
				ans++;
			}else{
				fa[x] = y;
				fa[sx] = sy;
				fa[bx] = by;
			}
		}else{
			int x= find(xx);
			int y = find(yy);
			int sx = find(xx+n);
			int sy = find(yy+n);
			int bx = find(xx+2*n);
			int by = find(yy+2*n);
			if(x==y||x==sy||y==bx){
				ans++;
			}else{
				fa[x] = by;
				fa[sx] = y;
				fa[bx] = sy;
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
