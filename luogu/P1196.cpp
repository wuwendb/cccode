// Problem: P1196 [NOI2002] 银河英雄传说
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1196
// Memory Limit: 128 MB
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
const int mx = 3e4+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  
int fa[mx],dis[mx],s[mx];
int find(int x) {
	if(fa[x]==x){
		return x;
	}
	int k = fa[x];
	fa[x] = find(fa[x]);
	dis[x] += dis[k];
	s[x] = s[fa[x]];
	return fa[x];
}
void dsu(){
	iota(begin(fa), end(fa), 0);
	rep(i,0,mx){
		s[i]=1;
		dis[i] = 0;
	}
}
  
void solve() {  
    int t;cin>>t;
    dsu();
    rep(i,1,t){
    	char op;cin>>op;int x,y;cin>>x>>y;
    	int rx = find(x);
		int ry = find(y);
    	if(op=='M'){
    		fa[rx] = ry;
    		dis[rx] += s[ry];
    		s[rx] += s[ry];
    		s[ry] = s[rx];
    	}else{
    		if(rx==ry){    			
				cout<<abs(dis[x]-dis[y])-1<<endl;
    		}else{
    			cout<<-1<<endl;
    		}
    	}
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
