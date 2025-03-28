// Problem: P1525 [NOIP2010 提高组] 关押罪犯
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1525
// Memory Limit: 125 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i) 
#define all(a) begin(a),end(a) 
//#define ll long long  
// #define int long long  
using namespace std;  
const int dx[4]{0,0,-1,1};
const int dy[4]{-1,1,0,0};
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  
struct crime{
	int a,b,c;
	bool operator<(const crime &a) const{
		return a.c<c;
	}
}x[mx];
int fa[mx];
int find(int x) {  
	return fa[x] == x ? x : fa[x] = find(fa[x]);  
}  
void dsu(){
	iota(begin(fa), end(fa), 0);
}  
void solve() {  
	dsu();
    int n,m;cin>>n>>m;
    vector<crime> g;
    rep(i,1,m){
    	int a,b,c;cin>>a>>b>>c;
    	g.emplace_back(a,b,c);
    }
    sort(all(g));
    rep(i,0,m-1){
    	int x = find(g[i].a);
    	int y = find(g[i].b);
    	if(x==y){
    		cout<<g[i].c<<endl;return;
    	}
    	fa[x] = find(g[i].b+n);
    	fa[y] = find(g[i].a+n);
    }
    cout<<0<<endl;
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
