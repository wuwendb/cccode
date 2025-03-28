// Problem: P2458 [SDOI2006] 保安站岗
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2458
// Memory Limit: 125 MB
// Time Limit: 1000 ms

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
const int mx = 2000;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  
vector<int> g[mx];
int val[mx];  
int indegree[mx];
tuple<int,int,int> dfs(int u){
	int choose = val[u],fa=0,son=0;
	int minson=INT_MAX/2;
	for(auto v:g[u]){
		auto [vchoose,vby_fa,vby_son] = dfs(v);
		fa += min(vchoose,vby_son);
		minson = min(vchoose-vby_son,minson);
		choose += min(vchoose,vby_fa);
	}
	son = fa+max(minson,0LL);
	return {choose,fa,son};
}
void solve() {  
    int n;cin>>n;
	rep(i,1,n){
		int ind,k,m;cin>>ind>>k>>m;
		val[ind]=k;
		rep(j,1,m){
			int x;cin>>x;
			indegree[x]++;
			g[ind].pb(x);
		}
	}
	rep(i,1,n){
		if(indegree[i]==0){
			auto [c,f,s] = dfs(i);
			cout<<min(c,s)<<endl;
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
